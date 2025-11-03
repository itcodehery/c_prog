/* New Language: ManasaKaHindi */

#include <stdio.h>
#define dena return
#define shuru {
#define khatam }
#define print_karo printf
#define jhode(x,y) x + y
#define sankya int
#define agar if
#define nahi_toh else
#define mujhe_de scanf_s

sankya main() shuru
	sankya num = 0;
	print_karo("Ek sankya dena: ");
	mujhe_de("%d",&num);
	agar (num > 0) shuru
		print_karo("\nPositive hai!");
	khatam nahi_toh shuru
		print_karo("\nNegative hain bhai!");
	khatam
	print_karo("\n%d",jhode(1,2));
	dena 0;
khatam
