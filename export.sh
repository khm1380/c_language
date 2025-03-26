#!/bin/bash
set -euo pipefail

USER_NAME="김현민"
EXPORT_DIR="export"
CMAKE_FILE="CMakeLists.txt"

log_info() {
    echo "[INFO] $*" >&2
}

log_error() {
    echo "[ERROR] $*" >&2
}

usage() {
    cat <<EOF
Usage:
  $0 <source_file.c>            # 파일 형식에 맞게 생성 ex) w2_<user_name>.c
  $0 <source_file.c> <week_num>   # 생성된 파일 업데이트
EOF
    exit 1
}

check_args() {
    if [ "$#" -ne 1 ] && [ "$#" -ne 2 ]; then
        usage
    fi
}

verify_file() {
    local source_file="$1"
    if [ ! -f "$source_file" ]; then
        log_error "Source file '$source_file' does not exist."
        exit 1
    fi
}

create_export() {
    mkdir -p "$EXPORT_DIR"
}

validate_week_number() {
    local num="$1"
    if ! [[ "$num" =~ ^[1-9][0-9]*$ ]]; then
        log_error "Week number must be a positive integer."
        exit 1
    fi
}

next_week_number() {
    local week_numbers=()
    for file in "$EXPORT_DIR"/W*_*.c; do
        [ -e "$file" ] || continue
        if [[ $(basename "$file") =~ ^W([0-9]+)_ ]]; then
            week_numbers+=("${BASH_REMATCH[1]}")
        fi
    done

    local next_week=1
    if [ ${#week_numbers[@]} -gt 0 ]; then
        local sorted=()

        while IFS= read -r line; do
            sorted+=("$line")
        done < <(printf "%s\n" "${week_numbers[@]}" | sort -n)

        local last_index=$(( ${#sorted[@]} - 1 ))
        local max_week="${sorted[$last_index]}"
        for n in $(seq 1 "$max_week"); do
            if ! printf "%s\n" "${sorted[@]}" | grep -qx "$n"; then
                next_week="$n"
                break
            fi
            next_week=$(( n + 1 ))
        done
    fi
    echo "$next_week"
}

check_syntax() {
    local source_file="$1"
    if ! gcc -std=c11 -Wall -Wextra -fsyntax-only "$source_file"; then
        log_error "Compilation errors detected in '$source_file'."
        exit 1
    fi
}

export_source() {
    local source_file="$1"
    local week_number="$2"
    local new_filename="W${week_number}_${USER_NAME}.c"
    cp "$source_file" "$EXPORT_DIR/$new_filename"
    echo "$new_filename"
}

update_cmake() {
    local new_filename="$1"
    local week_number="$2"
    local target_name="W${week_number}"
    if [ -f "$CMAKE_FILE" ]; then
        if ! grep -q "add_executable(${target_name} " "$CMAKE_FILE"; then
            {
                echo "# update: ${target_name} ($(date '+%Y-%m-%d %H:%M:%S'))"
                echo "add_executable(${target_name} \${CMAKE_SOURCE_DIR}/${EXPORT_DIR}/${new_filename})"
            } >> "$CMAKE_FILE"
            log_info "CMakeLists.txt updated with target '${target_name}'."
        else
            log_info "Target ${target_name} already exists in CMakeLists.txt."
        fi
    else
        log_info "CMakeLists.txt not found. Skipping CMake target update."
    fi
}

main() {
    check_args "$@"

    if [ "$#" -eq 1 ]; then
        local source_file="$1"
        verify_file "$source_file"
        create_export

        local next_week
        next_week=$(next_week_number)
        log_info "Next available week number: ${next_week}"

        check_syntax "$source_file"
        local new_filename
        new_filename=$(export_source "$source_file" "$next_week")
        log_info "File exported as ${EXPORT_DIR}/${new_filename}"

        update_cmake "$new_filename" "$next_week"

    elif [ "$#" -eq 2 ]; then
        local source_file="$1"
        local week_number="$2"
        verify_file "$source_file"
        validate_week_number "$week_number"
        create_export

        local target_file="${EXPORT_DIR}/W${week_number}_${USER_NAME}.c"
        if [ ! -f "$target_file" ]; then
            log_error "Target file for week number ${week_number} does not exist. Update aborted."
            exit 1
        fi

        check_syntax "$source_file"
        cp "$source_file" "$target_file"
        log_info "File updated as ${target_file}"
        log_info "CMakeLists.txt target for W${week_number} is assumed already exists."
    fi
}

main "$@"
