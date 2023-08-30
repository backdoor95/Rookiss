%include "io64.inc"

section .text
global main
main:
    mov rbp, rsp; for correct debugging
    
    ;write your code here
    
    ; 배열과 주소
    ; 배열 : 동일한 타입의 데이터 묶음
    ; - 배열을 구성하는 각 값을 배열 요소(element)라고 함.
    ; - 배열의 위치를 가리키는 숫자를 인덱스(index)라고 함.
    
    ; 주소
    ; [시작 주소 + 인덱스 * 크기]
    
    mov rax, a
    
    ; 연습문제 : a 배열의 모든 데이터 출력해보기
    ; 1) 하드 코딩 
    PRINT_HEX 1, [a]
    NEWLINE
    PRINT_HEX 1, [a+1]
    NEWLINE
    PRINT_HEX 1, [a+2]
    NEWLINE
    PRINT_HEX 1, [a+3]
    NEWLINE
    PRINT_HEX 1, [a+4]
    NEWLINE
    NEWLINE
    
    
    ; 2) JunHo Solution
    mov eax, a ; 반복 횟수 
    xor ebx, ebx ; mov ebx, 0   ebx에 결과물 저장 
    xor ecx, ecx ; 0으로 초기화 
LOOP_ARRAY:
    PRINT_HEX 1, [eax]
    NEWLINE
    add eax, 1
    inc ecx
    cmp ecx, 5
    jne LOOP_ARRAY
    
    NEWLINE
    NEWLINE
    
    ; 3) Rookiss Solution
    xor ecx, ecx
LABEL_PRINT_A:
    PRINT_HEX 1, [a+ecx]
    NEWLINE
    inc ecx
    cmp ecx, 5
    jne LABEL_PRINT_A
    
    
    ;나중에 c++에서 어셈블리를 까보는 이런 코드가 많이 나옴. 
    
    xor ecx, ecx
LABEL_PRINT_B:
    PRINT_HEX 2, [b+ecx*2]; [b+ecx] =>  0x00 0x01 --> 리틀 엔디언( 뒤집어서 )--> 0x0100
    ;1
    ;100
    ;1
    ;100
    ;1
    ; 이런 결과가 나온 이유는 2칸씩 가야하는데 1칸만 이동했기 때문이다. -> 어셈블리는 수동으로 컨트롤 해야함. => [b+ecx*2] 이렇게 2칸씩 이동시켜야함. 
    ; C++은 자동으로 타입에 크기에 따라서 이동함. 
    NEWLINE
    inc ecx
    cmp ecx, 5
    jne LABEL_PRINT_B
        
    
    
    
    
    
    
    xor rax, rax
    ret
    
    ;초기화 된 데이터
    ; [변수이름] [크기] [초기값]
    ; [크기] db(1) dw(2) dd(4) dq(8)

section .data
    msg db 'Hello World', 0x00 ; 0x00은 NULL를 의미함. 
    a db 0x01, 0x02, 0x03, 0x04, 0x05 ; db(1) * 5 = 5바이트 데이터
    
    ; 0x01 0x00 이렇게 되어있는 이유는 엔디안 때문이다. -> 0x0001이다.
    b times 5 dw 1 ; data 5개, 각 데이터의 크기는 2바이트, 초기값은 1로 세팅 -> dw(2) * 5 = 10 바이트 

    ; 2차 배열
    map1 db '#######', 0x00
    map2 db '#  #  #', 0x00
    map3 db '#######', 0x00

    ;초기화 되지 않은 데이터 = bss는 초기화 할 수 없다. 따라서 무조건 0으로 초기화됨.
    ; [변수이름] [크기] [개수]
    ; [크기] resb(1) resw(2) resd(4) resq(8)
section .bss
    num resb 10 ; 1바이트가 10개 짜리가 있다는 의미