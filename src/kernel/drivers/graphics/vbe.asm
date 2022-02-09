global drawPixel_s

drawPixel_s:use32
	push ebp
	mov ebp, esp

	push ebx
	push eax

	mov ebx, [ebp + 8]
	add ebx, [ebp + 12]
	mov eax, [ebp + 16]
	mov [ebx], eax

	pop eax
	pop ebx

	mov esp, ebp
	pop ebp
	ret
