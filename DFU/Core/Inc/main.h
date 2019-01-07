/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define LEDHum_Pin GPIO_PIN_1
#define LEDHum_GPIO_Port GPIOA
#define LEDTemp_Pin GPIO_PIN_3
#define LEDTemp_GPIO_Port GPIOA
#define EN_485_SEND_Pin GPIO_PIN_8
#define EN_485_SEND_GPIO_Port GPIOA
#define LEDAutoMan_Pin GPIO_PIN_6
#define LEDAutoMan_GPIO_Port GPIOF
#define LEDLoad_Pin GPIO_PIN_7
#define LEDLoad_GPIO_Port GPIOF
#define KeyAutoMan_Pin GPIO_PIN_4
#define KeyAutoMan_GPIO_Port GPIOB
#define KeySetEsc_Pin GPIO_PIN_5
#define KeySetEsc_GPIO_Port GPIOB

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */
#define SET_LED_AUTOMAN()			        (LEDAutoMan_GPIO_Port->ODR &= ~LEDAutoMan_Pin)
#define CLR_LED_AUTOMAN()			        (LEDAutoMan_GPIO_Port->ODR |= LEDAutoMan_Pin)
#define TOG_LED_AUTOMAN_OUT()			    (LEDAutoMan_GPIO_Port->ODR ^=  LEDAutoMan_Pin)
#define SET_LED_LOAD()			            (LEDLoad_GPIO_Port->ODR &= ~LEDLoad_Pin)
#define CLR_LED_LOAD()			            (LEDLoad_GPIO_Port->ODR |= LEDLoad_Pin)
#define TOG_LED_LOAD_OUT()			        (LEDLoad_GPIO_Port->ODR ^=  LEDLoad_Pin)
#define SET_LED_HUM()			            (LEDHum_GPIO_Port->ODR &= ~LEDHum_Pin)
#define CLR_LED_HUM()			            (LEDHum_GPIO_Port->ODR |= LEDHum_Pin)
#define TOG_LED_HUM_OUT()			        (LEDHum_GPIO_Port->ODR ^=  LEDHum_Pin)
#define SET_LED_TEMP()			            (LEDTemp_GPIO_Port->ODR &= ~LEDTemp_Pin)
#define CLR_LED_TEMP()			            (LEDTemp_GPIO_Port->ODR |= LEDTemp_Pin)
#define TOG_LED_TEMP_OUT()			        (LEDTemp_GPIO_Port->ODR ^=  LEDTemp_Pin)

#define SET_ALL_LED()                       {SET_LED_AUTOMAN();SET_LED_LOAD();SET_LED_HUM();SET_LED_TEMP();}         

#define BTN_AUTO_MAN_STATE()                (KeyAutoMan_GPIO_Port->IDR & KeyAutoMan_Pin)
#define BTN_SET_ESC_STATE()                 (KeySetEsc_GPIO_Port->IDR & KeySetEsc_Pin)

//485 send control
#define SET_485_DE()			            (EN_485_SEND_GPIO_Port->ODR |=  EN_485_SEND_Pin)
#define RST_485_DE()			            (EN_485_SEND_GPIO_Port->ODR &=  ~EN_485_SEND_Pin)
/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
