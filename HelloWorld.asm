%include "io64.inc"

section .text
global main
main:
           
    mov rbp, rsp; for correct debugging
    ;write your code here
    
    
    
    ;PRINT_STRING msg
    
    mov eax, 0x1234
    mov rbx, 0x12345678
    mov cl, 0xff
    
    mov al, 0x00   ;  하위 1바이트만 영향을 주고 상위비트는 영향을 못줌.
    ;mov rax, rdx
    
    ; memory <-> register
    ;mov rax, a ; a라는 바구니의 주소값을 rax에 복사
    ;mov rax, [a] ; a라는 바구니 안에 있는 값을rax에다 복사
    
    mov al, [a]
    
    
    
    
    ; 레지스터에 값을 넣기 [ --- ] 해줘야함. [] 없으면 주소가 들어감.
    
    mov [a], byte 0x55
    mov [a], word 0x6666
    mov [a], cl ; 이놈은 크기 표시가 필요없다. 왜나하면 cl 자체가 1byte를 의미하기 때문.
    
    
    
    mov rax, [a] ; a라는 바구니 안에 있는 값을 rax에 복사.

    
    
   
    xor rax, rax
    ret
    
    ; 변수의 선언 및 사용
    ; 변수는 그냥 데이터를 저장하는 바구니
    ; ~ 처음에 바구니 사용하겠다 선언 (이름과 크기 지정)

    ; 메모리에는 구분할 수 있도록 주소(번지수)가 있다.
    
    
    ; 초기화 된 데이터
    ; [변수이름] [크기] [초기값]
    ; [크기] db(1) dw(2) dd(4) dq(8)
section .data
    msg db 'hello world', 0x00
    
    a db 0x11 ; [0x11] 1byte
    b dw 0x2222 ; 2byte
    c dd 0x33333333; 4byte
    d dq 0x4444444444444444; 8byte
    
    
    ; 초기화 되지 않은 데이터 0으로 세팅
    ; [변수이름] [크기] [개수]
    ; [크기] resb(1) resw(2) resd(4) resq(8)
section .bss
    e resb 10