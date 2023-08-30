%include "io64.inc"

section .text
global main
main:
    mov rbp, rsp; for correct debugging
    
    ;write your code here
    
    ;반복문 (while, for, do-while)
    ;특정 조건을 만족할 때까지 반복해서 실행~
    
    ;ex) Hello World를 10번 출력해야 한다면?
    ; 1. 무식하게 하드코딩
    ; 2. 반복문을 이용
    
    mov ecx, 10; 통상적으로 count와 관련있는 값은ecx 레지스터 이용함.
    
LABEL_LOOP:
    PRINT_STRING msg
    NEWLINE
    dec ecx; [sub ecx, 1]과 동일함. 근데 des가 더 빠름 (decrease)
    cmp ecx, 0
    jne LABEL_LOOP
    
    ; 연습문제) 1에서 100까지의 합을 구하는 프로그램 1+2+3+4....+100=?
    ; 1)JUNHO SOLUTION  
    mov ecx, 0; 
    mov eax, 1; 
LABEL_COUNT_1TO100:
    add ecx, eax
    add eax, 1
    cmp eax, 101
    jne LABEL_COUNT_1TO100

    PRINT_DEC 4, ecx ;5050
    NEWLINE
    
    ; 2) Rookiss SOLUTION
    mov eax, 100
    xor ebx, ebx; mov ebx, 0와 동일함.   ebx에 결과장물 저장
    xor ecx, ecx

LABEL_SUM1:
    inc ecx; add ecx, 1과 동일
    add ebx, ecx
    cmp ecx, eax
    jne LABEL_SUM1
    
    PRINT_DEC 4, ebx
    NEWLINE
    
    ; 3) Rookiss SOLUTION
    ; loop [라벨]
    ; - ecx에 반복 횟수
    ; - loop 할때마다 ecx 1감소. 0이면 빠져나감. 아니면 라벨로 이동
    
    mov ecx, 100 ; 반복 횟수 
    xor ebx, ebx ; mov ebx, 0   ebx에 결과물 저장 
LABEL_LOOP_SUM:
    add ebx, ecx
    loop LABEL_LOOP_SUM ; 여기에 ecx를 1줄이는 코드가 들어있다. 
    
    PRINT_DEC 4, ebx
    NEWLINE
    
    
    
    xor rax, rax
    ret

section .data
    msg db 'Hello World', 0x00

section .bss
    e resb 10