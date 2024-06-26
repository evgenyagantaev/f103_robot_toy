/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "usart.h"
#include "gpio.h"

//#include "ssd1306.h"
#include "stdio.h"


void SystemClock_Config(void);

void led_blinc_light(int time);
void led_blinc_dark(int time);

int main(void)
{
	HAL_Init();

	SystemClock_Config();

	MX_GPIO_Init();
	MX_I2C1_Init();
	MX_USART1_UART_Init();
	MX_USART2_UART_Init();

	ssd1306_set_i2c_port(&hi2c1, 1);
	ssd1306_Init();
	HAL_Delay(100);

	/*
	ssd1306_Fill(White);
	ssd1306_UpdateScreen();
	HAL_Delay(100);
	ssd1306_Fill(Black);
	ssd1306_UpdateScreen();
	HAL_Delay(100);

	ssd1306_SetCursor(0,0);
	ssd1306_WriteString("ROBOT      ", Font_11x18, White);
	ssd1306_SetCursor(0,22);
	ssd1306_WriteString("GIGANT     ", Font_11x18, White);
	ssd1306_SetCursor(0,44);
	ssd1306_WriteString("           ", Font_11x18, White);
	ssd1306_UpdateScreen();
	HAL_Delay(1000);
	//*/


	HAL_GPIO_WritePin(onboard_led_GPIO_Port, onboard_led_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(GPIOB, eye1_led_Pin|eye2_led_Pin, GPIO_PIN_SET);

	int seconds_counter = 0;

	while (1)
	{
		//HAL_GPIO_WritePin(onboard_led_GPIO_Port, onboard_led_Pin, GPIO_PIN_SET);
		//HAL_Delay(500);
		//HAL_GPIO_WritePin(onboard_led_GPIO_Port, onboard_led_Pin, GPIO_PIN_RESET);
		//HAL_Delay(500);

		int i;
		for(i=0; i<7; i++)
		{
			led_blinc_light(30);
			HAL_Delay(30);
		}
		led_blinc_light(100);
		HAL_Delay(50);
		led_blinc_light(300);
		HAL_Delay(50);
		led_blinc_light(500);
		HAL_Delay(200);
		led_blinc_light(700);

		HAL_Delay(13000);
		led_blinc_light(700);

		HAL_Delay(7000);
		led_blinc_light(700);
		HAL_Delay(200);
		led_blinc_light(500);
		HAL_Delay(50);
		led_blinc_light(300);
		HAL_Delay(50);
		led_blinc_light(100);

		HAL_Delay(13000);
		for(i=0; i<11; i++)
		{
			led_blinc_light(30);
			HAL_Delay(30);
		}
		HAL_Delay(200);
		led_blinc_light(700);

		HAL_Delay(23000);
		led_blinc_light(100);
		HAL_Delay(50);
		led_blinc_light(300);
		HAL_Delay(50);
		led_blinc_light(500);
		HAL_Delay(200);
		led_blinc_light(700);

		HAL_Delay(41000);
	}
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */


void led_blinc_light(int time)
{
	HAL_GPIO_WritePin(eye1_led_GPIO_Port, eye1_led_Pin, GPIO_PIN_SET);
	HAL_Delay(time);
	HAL_GPIO_WritePin(eye1_led_GPIO_Port, eye1_led_Pin, GPIO_PIN_RESET);
}
void led_blinc_dark(int time)
{
	HAL_Delay(time);
}
