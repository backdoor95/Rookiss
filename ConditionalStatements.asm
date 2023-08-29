%include "io64.inc"

section .text
global main
main:
    mov rbp, rsp; for correct debugging
    ;gpt : 스택 프레임을 설정할 때 rbp 와 rsp를 일치시켜야함.
    ;디버거가 스택을 더 쉽게 관리할 수 있도록 하기 위함. 일반적으로, 디버거는 rbp를 사용하여 로컬 변수와 함수의 반환 주소 등을 찾습니다.
    ;rbp와 rsp가 일치하지 않으면, 디버거는 스택 프레임을 올바르게 해석하는 데 어려움을 겪을 수 있습니다.
    
    ;write your code here
    
    
    ; 분기문(if)
    ; 특정 조건에 따라서 코드 흐름을 제어하는 것
    ; ex) 스킬 버튼 눌렀는가? yes -> 스킬사용
    ; ex) 제한 시간 내에 던전 입장 수락 버튼을 눌렀는가? yes -> 입장, no -> 던전 취소
    
    ;조건 -> 흐름
    
    ; CMP (compare)
    ; CMP dst, src (dst가 기준)
    ; 비교를 한 결과물은 Flag Register 저장
    
    ; JMP [label] 시리즈
    ; JMP : 무조건 jump
    ; JE : JumpEquals 같으면 jump
    ; JNE : JumpNotEquals 다르면 jump
    ; JG : JumpGreater 크면 jump
    ; JGE : JumpGreaterEquals 크거나 같으면 jump
    ; JL
    ; JLE
    
    ; 두 숫자가 같으면 1, 아니면 0을 출력하는 프로그램
    
    mov rax, 10
    mov rbx, 10 
    ; 같지 않다면 eflag info = [ CF PF SF IF ] 
    ; 같다면 eflag info = [ PF ZF IF ]
    cmp rax, rbx
    
    je LABEL_EQUAL
    
    ;je에 의해 점프를 안했다면, 같지 않다는 의미
    mov rcx, 0
    jmp LABEL_EQUAL_END
    
LABEL_EQUAL: 
    mov rcx, 1
LABEL_EQUAL_END:
    PRINT_HEX 1, rcx
    NEWLINE
    
    
    ; 연습문제
    ; = 어떤 숫자(1~100)가 짝수면 1, 홀수면 0을 출력하는 프로그램
    mov ax, 99
    
    ; 나누기 연산
    ; div reg
    ; - div bl => ax / bl (al 몫 ah 나머지)
    
    ; JunHo 풀이
    mov bl, 2
    div bl
    cmp ah, 0 ; 짝수
    je LABEL_EVEN
    
    ; je에 의해 점프를 안했다면, 같지 않다는 의미 -> 홀수라는 의미
    mov rcx, 0
    jmp LABEL_ODD

LABEL_EVEN:
    mov rcx, 1
LABEL_ODD:
    PRINT_HEX 1, rcx
    NEWLINE
    
    ;Rookiss 풀이
    mov bl, 2
    div bl
    cmp ah, 0
    je L1; 짝수
    mov rcx, 0
    jmp L2; 홀수
    
    
L1:
    mov rcx, 1
L2:
    PRINT_HEX 1, rcx
    NEWLINE
    
    
    
    xor rax, rax
    ret

section .data


section .bss
    e resb 10