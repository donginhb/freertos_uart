#ifndef __WIEGAND_H
#define __WIEGAND_H

#ifdef __cplusplus
extern "C" {
#endif

#include "sys.h"	


#define WIEGAND_UNIT_LENGHT 8	
#define WIEGAND_BIT_LENGHT  66	
#define WIEGAND_BYTE_NUM	(WIEGAND_BIT_LENGHT/WIEGAND_UNIT_LENGHT + 1)	


typedef enum Wiegand_Sequence_Type_t
{
	Wiegand_Sequence_Normal 		= 0x00,//正常
	Wiegand_Sequence_Reversal 	= 0x01,//倒序
	Wiegand_Sequence_NOT			= 0x02,//取反
  Wiegand_Sequence_HighStart 		= 0x04,//从高（低）开始取指定位数
}Wiegand_Sequence_Type;


	
typedef enum ReadHead_State_t
{
	ReadHead_IDLE 		= 0, 	//空闲状态
	ReadHead_RECEIVE	= 1,	//正在接收
	ReadHead_FINISH	= 2,	//接收完毕	
}ReadHead_State;

typedef enum CardDevice_State_t
{	
	CardDev_IDLE 		= 0, 	//空闲状态	
	CardDev_RECEIVE	= 1,	//正在接收	
	CardDev_FINISH		= 2,	//接收完毕	
}CardDevice_State;			



typedef struct WIEGAND_PARAM_t		
{	
	CardDevice_State State;			//刷卡头状态
	u8 KeyNumber;
	u8 Pos;				//接收数存储wiegand的字节的位置   
	
	u8 bits[WIEGAND_BYTE_NUM];//真实数据		
	u8 num_bits;	
	
}WIEGAND_PARAM;	

	
	

void wiegand_reader_d0(u8 pin,u8 state);
void wiegand_reader_d1(u8 pin,u8 state);
void wiegand_reader_d2(u8 pin,u8 state);
void wiegand_reader_d3(u8 pin,u8 state);


void wiegand_reader_init(WIEGAND_PARAM *wg_buf);


		
#endif 
