[bits 32]
extern TimeHandler

global timer
TimeHandler:
    pusha
    call TimeHandler
    popa
    iretd