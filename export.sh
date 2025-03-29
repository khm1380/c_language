#!/bin/bash
set -euo pipefail

declare -r USER_NAME="김현민"
declare -r EXPORT_DIR="export"
declare -r CMAKE_FILE="CMakeLists.txt"
declare -r WEEK_FILE_REGEX="^W([0-9]+)_"
declare -r WEEK_FILE_GLOB="W*_*.c"  # 파일 탐색 패턴
declare -r FILE_NAME_FORMAT="W%s_${USER_NAME}.c"  # 파일 이름 형식

log_info() {
    echo "[INFO] $*" >&2
}

log_error() {
    echo "[ERROR] $*" >&2
}

usage() {
    cat <<EOF
사용 방법:
  $0 <source_file.c>            # 파일 생성 (예: W<week_num>_${USER_NAME}.c)
  $0 <source_file.c> <week_num>   # 기존 파일 업데이트
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
        log_error "입력하신 파일 '$source_file'이(가) 존재하지 않아요. 경로를 확인해 주세요."
        exit 1
    fi
}

create_export() {
    mkdir -p "$EXPORT_DIR"
}

validate_week_number() {
    local num="$1"
    if ! [[ "$num" =~ ^[1-9][0-9]*$ ]]; then
        log_error "주차 번호는 양의 정수여야 해요. 다시 입력해 주세요."
        exit 1
    fi
}

next_week_number() {
    local week_numbers=()
    for file in "$EXPORT_DIR"/$WEEK_FILE_GLOB; do
        [ -e "$file" ] || continue
        if [[ $(basename "$file") =~ $WEEK_FILE_REGEX ]]; then
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
        log_error "소스 파일 '$source_file'에 문법 오류가 있어요. 확인 부탁드려요."
        exit 1
    fi
}

export_source() {
    local source_file="$1"
    local week_number="$2"
    local new_filename
    new_filename=$(printf "$FILE_NAME_FORMAT" "$week_number")
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
            log_info "CMakeLists.txt에 타겟 '${target_name}'을(를) 추가했어요."
        else
            log_info "CMakeLists.txt에 이미 타겟 '${target_name}'이(가) 등록되어 있어요."
        fi
    else
        log_info "CMakeLists.txt 파일을 찾지 못했어요."
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
        log_info "다음 주차 번호는 ${next_week}예요."

        check_syntax "$source_file"
        local new_filename
        new_filename=$(export_source "$source_file" "$next_week")
        log_info "파일이 ${EXPORT_DIR}/${new_filename}로 저장되었어요."

        update_cmake "$new_filename" "$next_week"

    elif [ "$#" -eq 2 ]; then
        local source_file="$1"
        local week_number="$2"
        verify_file "$source_file"
        validate_week_number "$week_number"
        create_export

        local target_file
        target_file=$(printf "%s/%s" "$EXPORT_DIR" "$(printf "$FILE_NAME_FORMAT" "$week_number")")
        if [ ! -f "$target_file" ]; then
            log_error "주차 번호 ${week_number}에 해당하는 파일이 없어요. 업데이트를 중단할게요."
            exit 1
        fi

        check_syntax "$source_file"
        cp "$source_file" "$target_file"
        log_info "파일이 ${target_file}로 업데이트되었어요."
    fi
}

main "$@"
