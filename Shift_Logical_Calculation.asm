%include "io64.inc"

section .text
global main
main:
    ;write your code here
    
    ; shift 연산, 논리(logical) 연산
    mov eax, 0x12345678
    PRINT_HEX 4, eax
    NEWLINE
    
    shl eax, 8    
    PRINT_HEX 4, eax
    NEWLINE
    
    shr eax, 8
    PRINT_HEX 4, eax
    NEWLINE
    ;12345678
    ;34567800
    ;345678
    
    ;shift 연산을 하는 이유
    ; 곱셈/나눗셈
    ; 게임서버에서 ObjectID를 만들때
    
    
    ;논리연산
    ;not and or xor
    
    ;조건A : 잘생겼다
    ;조건B : 키가 크다
    
    ;not A : 잘생겼다의 반대 -> {0이면 1, 1이면 0}
    ;A and B : 잘생겼고 and 키도 크고 -> 둘다1이면, 아니면 0
    ;A or B : 잘생겼거나 or 키가 크거나 -> 둘중 하나라도 1이면 1, 아니면 0
    ;A xor B : 잘생기고 작거나 or 못생기고 크거나 -> 둘다 1이거나 둘다 0이면, 아니면 1
    
    mov al, 0b10010101
    mov bl, 0b01111100
    
    ;0b0001 0100 = 0x14
    and al, bl ; al = al and bl
    PRINT_HEX 1, al
    NEWLINE
    
    ;0b1110 1011 = 0xeb
    not al
    PRINT_HEX 1, al
    NEWLINE    
    
    
    ; 응용 사례 : bit flag
    ; 비트마다 의미를 부여하기 -> and , or 연산이용
    
    
    ; 동일한 값으로 xor 두번하면 자기 자신으로 되돌아오는 특성
    ; 암호학에서 유용하다! (value xor key) -> 대칭키 암호를 사용할때
    
    
    
    mov al, 0b10010101
    mov bl, 0b01111100
    
    NEWLINE
    PRINT_HEX 1, al
    NEWLINE
    
    xor al, bl
    PRINT_HEX 1, al
    NEWLINE
    
    xor al, bl
    PRINT_HEX 1, al
    NEWLINE    
    
    
    ;mov al, 0
    xor al, al ; 자기 자신이랑 xor를 하면 항상 0 --->> 사실상 mov al, 0 ---> mov 연산보다 xor연산이 빠르다.
    PRINT_HEX 1, al
    
    
    
    
    
    xor rax, rax
    ret

section .data

section .bss
    e resb 10