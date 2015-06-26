/*
 *	zhizhu.h
 *	蜘蛛ID号定义
 *
 *
 */

  

//舵机ID号定义
#define L_ID_11	40
#define L_ID_12	31
#define L_ID_13	30

#define L_ID_21	41
#define L_ID_22	42
#define L_ID_23	50

#define L_ID_31	53
#define L_ID_32	51 
#define L_ID_33	52
///////////////////
#define R_ID_11	32
#define R_ID_12	20
#define R_ID_13	21

#define R_ID_21	22
#define R_ID_22	10
#define R_ID_23	11

#define R_ID_31	2
#define R_ID_32	1
#define R_ID_33	3
/////////////////////////////

// index for id_array[]
// #define SERVO_NUM 18
// #define LI_11	0	
// #define LI_12	1
// #define LI_13	2
//           
// #define LI_21	3
// #define LI_22	4
// #define LI_23	5
//           
// #define LI_31	6
// #define LI_32	7
// #define LI_33	8
// /////////I_//////
// #define RI_11	9
// #define RI_12	10
// #define RI_13	11
//           
// #define RI_21	12
// #define RI_22	13
// #define RI_23	14
//           
// #define RI_31	15
// #define RI_32	16
// #define RI_33	17

//uint8_t id_array[SERVO_NUM] = {40, 31, 30, 41, 42, 50, 53, 51, 52, 32, 20, 21, 22, 10, 11, 2, 1, 3};

//////////////////

// 舵机方向与位置映射

#define LG11(pos)	(150+((pos) - 60))	//前腿后摆
#define LG12(pos)	(300-(pos))
#define LG13(pos)	(300-(pos))

#define LG21(pos)	(150+(pos))
#define LG22(pos)	(300-(pos))
#define LG23(pos)	(300-(pos))

#define LG31(pos)	(150+((pos) + 50))	//后腿前摆
#define LG32(pos)	(300-(pos))
#define LG33(pos)	(300-(pos))
////////////////////////////////////////////
#define RG11(pos)	(150-((pos) - 60))
#define RG12(pos)	(pos)
#define RG13(pos)	(pos)

#define RG21(pos)	(150-(pos))
#define RG22(pos)	(pos)
#define RG23(pos)	(pos)

#define RG31(pos)	(150-((pos) + 70))
#define RG32(pos)	(pos)
#define RG33(pos)	(pos)
////////////////////////////////////////////


