%include "io64.inc"

section .text
global main
main:
    mov rbp, rsp; for correct debugging - > 요놈이 bp, sp를 의미함.
    
    ;write your code here
    
    ; 스택 메모리, 스택 프레임
    
    ; 레지스터는 다양한 용도로 사용
    ; - a b c d 범용 레지스터
    ; - 포인터 레지스터 (포인터 = 위치를 가리키는~)
    ; -- ip (Instruction Pointer) : 다음 수행 명령어의 위치를 가리킴
    ; -- sp (Stack Pointer) :  현재 스택 top 위치( 일종의 cursor)
    ; -- bp (Base Pointer) : 스택 상대주소 계산용
    ; push 할때 기본적으로 8바이트로 인식함.
    push 1
    push 2 ; push 할때 기본적으로 8바이트로 인식함.
    push 3
    
    pop rax
    pop rbx
    pop rcx
    
    push rax
    push rbx
    push 1
    push 2
    call MAX ; 점프와 콜의 차이점은 return 의 여부
    PRINT_DEC 8, rax
    NEWLINE
    add rsp, 16 ;push를 할때마다 rsp가 8씩 이동
    ;스택을 사용했으면 깔끔하기 정리해야함.*********
    ; 위에서 push 2번 했으니 
    ; 1. pop 을 2번 하거나
    ; 2. add rsp, 16을 해줘야함. [2칸 복원]
    pop rbx
    pop rax
    
    
    
    xor rax, rax
    ret
    
MAX:
;c++ 이나 다른 언어를 컴파일해서 어셈블리언어로 까보면
; 아래와 같은 패턴이 나옴
    push rbp 
    mov rbp, rsp
    
    mov rax, [rbp+16]
    mov rbx, [rbp+24]
    cmp rax, rbx
    jg L1
    mov rax, rbx
L1:
    pop rbp
    ret 
    ;push rbp, pop rbp를 하는 이유
    ; --> 함수안에서 함수를 호출할 수 있기 때문에
    ; 꿈에서 꿈을꿈
    ; pop rbp를 통해서 bp값을 복원
    
    ;리턴을 하게 되는데 어떻게 리턴할까?
    ; ip 에 내가 실행하고 있는 위치를 저장해두고 있는데, ip에 저장된 주소를 stack에 저장해서[[이전 bp값], 함수가 끝나면 해당 주소로 복귀한다.
    

section .data
    msg db 'Hello World', 0x00

section .bss
    e resb 10