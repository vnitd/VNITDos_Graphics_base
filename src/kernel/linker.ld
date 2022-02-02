ENTRY("kernel_main")

SECTIONS
{
    .text 0x1400 :
    {
        *(.text*);
    }
    .rodata :
    {
        *(.rodata*);
    }
    .bss :
    {
        *(.bss*);
    }
}