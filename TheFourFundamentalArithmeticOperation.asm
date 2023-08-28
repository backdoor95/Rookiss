%include "io64.inc"

section .text
global main
main:
    ;write your code here
    ;
    
    GET_DEC 1, al   ; 어떤 숫자를 입받고 싶을때, input 창을 통해서 --> 1 바이트(크기), 변수명
    GET_DEC 1, num
    
    ;PRINT_DEC 1, al
    ;NEWLINE
    ;PRINT_DEC 1, num
    
    ; 사칙연산
    
    ; 1. 더하기 연산
    ; add a, b(a = a + b)
    ; 어셈블리코드는 대문자로 작성해도 되고, 소문자로 작성해도됨. -> 취향차이
    ; a는 레지스터 or 메모리
    ; b는 레지스터 or 메모리 or 상수
    ; 단! a, b 모두 메모리는 X
    
    add al, 1 ; 레지스터 + 상수 = register + const
    PRINT_DEC 1, al ; 1+1 = 2
    NEWLINE
    
    
    ;add al, num ; 이렇게 해면 크래쉬가 발생함. num 자체는 주소를 의미함. 값을 넣으려면 [num] 해야함.
    add al, [num] ;********* register + memory  2 + 2 = 4
    PRINT_DEC 1, al
    NEWLINE
    
    
    mov bl, 3 ; 3을 넣어준다. ********* register + register
    add al, bl ; 4+3 =7
    PRINT_DEC 1, al
    NEWLINE
    
    
    
    ;add [num], 1 ; 이렇게 하면 에러발샐
    ; ********* memory + const
    add [num], byte 1 ; 상수에다가 크기를 붙여야한다. 어떤크기로 분석해야하는지 판단해서 더해줘야함.
    PRINT_DEC 1, [num] ;2+1 = 3
    NEWLINE
    
    
    
    ; ********* memory + register
    add [num], al ; 3+7 = 10
    PRINT_DEC 1, [num]
    NEWLINE
    
    
    ; 2. 빼기 연산
    ; sub a, b(a = a - b)
    ; 이건 덧셈과 유사하므로 패스
    
    
    ; 3. 곱하기 연산
    ;mul reg -- a register는 예약되어있다.
    ; - mul bl => al * bl
    ; -- 연산 결과를 ax에 저장
    ; - mul bx => ax * bx
    ; -- 연산 결과는 dx(상위 16비트) ax(하위 16비트)에 저장
    ; - mul ebx => eax * ebx
    
    ;ex) 5 * 8 ?
    mov ax, 0
    mov al, 5
    mov bl, 8
    mul bl
    PRINT_DEC 2, ax
    NEWLINE
    
    
    
    ; 4. 나누기 연산
    ; div reg
    ; - div bl => ax/bl
    ; -- 연산 결과는 al(몫) ah (나머지)
    
    ; ex) 100/3 ?
    mov ax, 100
    mov bl, 3
    div bl
    PRINT_DEC 1, al ; 100 / 3 = 33 * 3 +1
    NEWLINE
    mov al, ah ; ah는 print_dec로 표현이 불가해서 이런꼼수를 사용
    PRINT_DEC 1, al
    
    
    
    
    xor rax, rax
    ret

section .bss
    num resb 1 ;num 자체는 생 메모리 주소이다.