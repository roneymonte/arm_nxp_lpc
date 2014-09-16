/*
 * (C) Code Red Technologies Ltd, 2008-9    
 * Generated C linker script file for LPC1114/301 
 * (created from nxp_lpc11_c.ld (v3.3.4 (201004081702)) on Fri Jul 09 14:16:31 PDT 2010)
*/

INCLUDE "../ld/custom_lib.ld"
INCLUDE "../ld/custom_mem.ld"

ENTRY(ResetISR)

SECTIONS
{
	/*
	Normally the exception vector contains wakeup entries. Because this project doesn't use low power modes
	it is safe to replace these vectors with other code/constant data. In this case the small_gpio look up
	table has been used.
	In the remaining 0xC bytes, the IntDefaultHandler() at 0x4 bytes has also been included.
	*/
	.text :
	{
		KEEP(*(.reset_vector))
		KEEP(*(.vector_const))
		. = 0x7C;
		KEEP(*(.isr_vector))
		. = 0xC0;
		*(.text*)
		*(.rodata*)

	} > MFlash32


	/* for exception handling/unwind - some Newlib functions (in common with C++ and STDC++) use this. */
	
	.ARM.extab : 
	{
		*(.ARM.extab* .gnu.linkonce.armextab.*)
	} > MFlash32

	__exidx_start = .;
	.ARM.exidx :
	{
		*(.ARM.exidx* .gnu.linkonce.armexidx.*)
	} > MFlash32
	__exidx_end = .;

	_etext = .;
		
	.data : AT (__exidx_end)
	{
		_data = .;
		*(vtable)
		*(.data*)
		_edata = .;
	} > RamLoc8

	/* zero initialized data */
	.bss :
	{
		_bss = .;
		*(.bss*)
		*(COMMON)
		_ebss = .;
	} > RamLoc8
	
	/* Where we put the heap with cr_clib */
	.cr_heap :
	{
		end = .;
		_pvHeapStart = .;
	} > RamLoc8

/*
	Note: (ref: M0000066)
	Moving the stack down by 16 is to work around a GDB bug.
	This space can be reclaimed for Production Builds.
*/	
	_vRamTop = __top_RamLoc8 ;
	_vStackTop = _vRamTop - 16;
}
