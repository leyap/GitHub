//蜘蛛

#include "hexapod_map.h"
//#include "cds55.h"

//ServoCds55 myservo;
//#define L11(x)	( myservo.WritePos (L_ID_11, LG11(x)) )

#define L11(x)	( cds55_pos (L_ID_11, LG11(x)) )
#define L12(x)	( cds55_pos (L_ID_12, LG12(x)) )
#define L13(x)	( cds55_pos (L_ID_13, LG13(x)) )
#define L21(x)	( cds55_pos (L_ID_21, LG21(x)) )
#define L22(x)	( cds55_pos (L_ID_22, LG22(x)) )
#define L23(x)	( cds55_pos (L_ID_23, LG23(x)) )
#define L31(x)	( cds55_pos (L_ID_31, LG31(x)) )
#define L32(x)	( cds55_pos (L_ID_32, LG32(x)) )
#define L33(x)	( cds55_pos (L_ID_33, LG33(x)) )
                  
#define R11(x)	( cds55_pos (R_ID_11, RG11(x)) )
#define R12(x)	( cds55_pos (R_ID_12, RG12(x)) )
#define R13(x)	( cds55_pos (R_ID_13, RG13(x)) )
#define R21(x)	( cds55_pos (R_ID_21, RG21(x)) )
#define R22(x)	( cds55_pos (R_ID_22, RG22(x)) )
#define R23(x)	( cds55_pos (R_ID_23, RG23(x)) )
#define R31(x)	( cds55_pos (R_ID_31, RG31(x)) )
#define R32(x)	( cds55_pos (R_ID_32, RG32(x)) )
#define R33(x)	( cds55_pos (R_ID_33, RG33(x)) )

//
void ctrl_all_leg (int p1, int p2, int p3) {
	L11(p1); L12(p2); L13(p3);
	L21(p1); L22(p2); L23(p3);
	L31(p1); L32(p2); L33(p3);
	R11(p1); R12(p2); R13(p3);
	R21(p1); R22(p2); R23(p3);
	R31(p1); R32(p2); R33(p3);
}

//
void first_step (int p1, int p2, int p3, int t) {
	//p1, p2+70, p3/2+50
	L11(p1); R21(t*p1); L31(p1);
	L12(p2); R22(p2); L32(p2);
	L13(p3); R23(p3); L33(p3);
}

//
void second_step (int p1, int p2, int p3, int t) {
	R11(p1); L21(t*p1); R31(p1);
	R12(p2); L22(p2); R32(p2);
	R13(p3); L23(p3); R33(p3);
}

//
void left_two (int p1, int p2, int p3, int t) {
	L11(p1); L31(p1);
	L12(p2); L32(p2);
	L13(p3); L33(p3);
}
void left_one (int p1, int p2, int p3, int t) {
	L21(t*p1); L22(p2); L23(p3); 
}
void right_two (int p1, int p2, int p3, int t) {
	R11(p1); R31(p1);
	R12(p2); R32(p2);
	R13(p3); R33(p3);
}
void right_one (int p1, int p2, int p3, int t) {
	R21(t*p1); R22(p2); R23(p3); 	
}

