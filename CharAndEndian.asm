%include "io64.inc"

section .text
global main
main:
           
    mov rbp, rsp; for correct debugging
    ;write your code here
    
    PRINT_STRING msg
    
    xor rax, rax
    ret
    
    
    ; 초기화 된 데이터
    ; [변수이름] [크기] [초기값]
    ; [크기] db(1) dw(2) dd(4) dq(8)
section .data
    ;msg db 'hello world', 0x00
    msg db 0x68, 0x65, 0x6c, 0x6c, 0x6f, 0x20, 0x77, 0x6f, 0x72, 0x6c, 0x64, 0x0 ; 이거는 hello world
    
    a db 0x11, 0x11, 0x11, 0x11; [0x11]
    
    b dd 0x12345678
    ; 장단점이 교차한다
    ; - 리틀 엔디언 : 캐스팅에서는 리틀 엔디안이 유리
    ; - 빅 엔디언 : 숫자 비교에 유리

    
    
    ; 초기화 되지 않은 데이터 0으로 세팅
    ; [변수이름] [크기] [개수]
    ; [크기] resb(1) resw(2) resd(4) resq(8)
section .bss
    e resb 10