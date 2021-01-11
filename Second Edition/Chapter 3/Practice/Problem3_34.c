/*
 For a C function having the general structure
 int rfun(unsigned int x){
     if (________){
         return ____;
     unsigned nx = _________;
     int rv = rfun(nx);
     return _________;
 }

GCC generates the following assembly code (with the setup and
completion code ommitted):
   movl     8(%ebp), %ebx  --- %ebx = var1
   movl     $0, %eax  --- %eax = 0
   testl    %ebx, %ebx -- test ebx == ebx
   je       .L3 -- branch if ebx == 0 
   movl     %ebx, %eax -- %eax = %ebx
   shrl     %eax     -- Shift logical right by 1 
   movl     %eax, (%esp) -- *%esp = %eax
   call     rfun  -- Call function
   movl     %ebx, %edx -- %edx = %ebx
   andl     $1, %edx  -- %edx &= 1
   leal     (%edx, %eax), %eax  %eax = (%edx + %eax)
.L3

A) What value does rfun store in the callee-save register %ebx?
An argument sent by the caller (which is argument x)

B) Fill in the missing expressions in the C code shown above.

C) Describe in English what function this code computes:


*/


int rfun(unsigned x){
    if (x == 0)
        return 0;
    unsigned nx = x >> 1;
    int rv = rfun(nx);
    return x + rv;
}
    

int main(void){
    return 0;
}
