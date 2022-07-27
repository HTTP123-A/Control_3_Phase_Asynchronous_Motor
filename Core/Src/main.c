/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define NS			512
#define	TIMER1_CLk	100000000

uint16_t Sine_LUT_P1[NS] = {
		512, 518, 524, 530, 537, 543, 549, 555, 562, 568, 574, 580, 587, 593, 599, 605, 611, 618, 624, 630, 636, 642, 648, 654, 660, 666, 672, 678, 684, 690,
		696, 702, 708, 713, 719, 725, 731, 736, 742, 747, 753, 759, 764, 770, 775, 780, 786, 791, 796, 801, 807, 812, 817, 822, 827, 832, 837, 841, 846, 851,
		856, 860, 865, 869, 874, 878, 883, 887, 891, 895, 899, 903, 907, 911, 915, 919, 923, 927, 930, 934, 937, 941, 944, 948, 951, 954, 957, 960, 963, 966,
		969, 972, 974, 977, 980, 982, 985, 987, 989, 991, 994, 996, 998, 999, 1001, 1003, 1005, 1006, 1008, 1009, 1011, 1012, 1013, 1015, 1016, 1017, 1018,
		1019, 1019, 1020, 1021, 1021, 1022, 1022, 1022, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1022, 1022, 1021, 1021, 1020, 1020, 1019, 1018, 1017, 1016,
		1015, 1014, 1013, 1012, 1010, 1009, 1007, 1006, 1004, 1002, 1000, 999, 997, 995, 992, 990, 988, 986, 983, 981, 978, 976, 973, 970, 967, 965, 962, 959,
		956, 952, 949, 946, 942, 939, 936, 932, 928, 925, 921, 917, 913, 909, 905, 901, 897, 893, 889, 885, 880, 876, 872, 867, 862, 858, 853, 849, 844, 839,
		834, 829, 824, 819, 814, 809, 804, 799, 794, 788, 783, 778, 772, 767, 761, 756, 750, 745, 739, 733, 728, 722, 716, 711, 705, 699, 693, 687, 681, 675,
		669, 663, 657, 651, 645, 639, 633, 627, 621, 615, 608, 602, 596, 590, 584, 577, 571, 565, 559, 552, 546, 540, 534, 527, 521, 515, 508, 502, 496, 489,
		483, 477, 471, 464, 458, 452, 446, 439, 433, 427, 421, 415, 408, 402, 396, 390, 384, 378, 372, 366, 360, 354, 348, 342, 336, 330, 324, 318, 312, 307,
		301, 295, 290, 284, 278, 273, 267, 262, 256, 251, 245, 240, 235, 229, 224, 219, 214, 209, 204, 199, 194, 189, 184, 179, 174, 170, 165, 161, 156, 151,
		147, 143, 138, 134, 130, 126, 122, 118, 114, 110, 106, 102, 98, 95, 91, 87, 84, 81, 77, 74, 71, 67, 64, 61, 58, 56, 53, 50, 47, 45, 42, 40, 37, 35,
		33, 31, 28, 26, 24, 23, 21, 19, 17, 16, 14, 13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 3, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 4, 4, 5, 6, 7, 8,
		10, 11, 12, 14, 15, 17, 18, 20, 22, 24, 25, 27, 29, 32, 34, 36, 38, 41, 43, 46, 49, 51, 54, 57, 60, 63, 66, 69, 72, 75, 79, 82, 86, 89, 93, 96, 100,
		104, 108, 112, 116, 120, 124, 128, 132, 136, 140, 145, 149, 154, 158, 163, 167, 172, 177, 182, 186, 191, 196, 201, 206, 211, 216, 222, 227, 232,237,
		243, 248, 253, 259, 264, 270, 276, 281, 287, 292, 298, 304, 310, 315, 321, 327, 333, 339, 345, 351, 357, 363, 369, 375, 381, 387, 393, 399, 405, 412,
		418, 424, 430, 436, 443, 449, 455, 461, 468, 474, 480, 486, 493, 499, 505, 511
};

uint16_t Sine_LUT_P2[NS] = {
		69, 65, 62, 59, 56, 54, 51, 48, 46, 43, 41, 38, 36, 33, 31, 29, 27, 25, 23, 21, 20, 18, 16, 15, 13, 12, 11, 9, 8, 7, 6, 5, 4, 4, 3, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0,
		0, 0, 1, 1, 2, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 15, 16, 18, 19, 21, 23, 25, 27, 29, 31, 33, 35, 38, 40, 43, 45, 48, 50, 53, 56, 59, 62, 65, 68, 71, 74, 78,
		81, 85, 88, 92, 95, 99, 103, 106, 110, 114, 118, 122, 126, 131, 135, 139, 143, 148, 152, 157, 161, 166, 171, 175, 180, 185, 190, 195, 200, 205, 210, 215, 220, 225,
		230, 236, 241, 246, 252, 257, 263, 268, 274, 279, 285, 291, 296, 302, 308, 313, 319, 325, 331, 337, 343, 349, 355, 361, 367, 373, 379, 385, 391, 397, 403, 409, 416,
		422, 428, 434, 440, 447, 453, 459, 465, 472, 478, 484, 491, 497, 503, 509, 516, 522, 528, 535, 541, 547, 553, 560, 566, 572, 578, 585, 591, 597, 603, 609, 616, 622,
		628, 634, 640, 646, 652, 658, 664, 670, 676, 682, 688, 694, 700, 706, 711, 717, 723, 729, 734, 740, 746, 751, 757, 762, 768, 773, 779, 784, 789, 794, 800, 805, 810,
		815, 820, 825, 830, 835, 840, 845, 849, 854, 859, 863, 868, 872, 877, 881, 885, 890, 894, 898, 902, 906, 910, 914, 918, 922, 925, 929, 933, 936, 940, 943, 946, 950,
		953, 956, 959, 962, 965, 968, 971, 973, 976, 979, 981, 984, 986, 988, 991, 993, 995, 997, 999, 1001, 1003, 1004, 1006, 1007, 1009, 1010, 1012, 1013, 1014, 1015,
		1016, 1017, 1018, 1019, 1020, 1020, 1021, 1022, 1022, 1022, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1022, 1022, 1022, 1021, 1021, 1020, 1019, 1018, 1018, 1017,
		1016, 1014, 1013, 1012, 1011, 1009, 1008, 1006, 1005, 1003, 1001, 999, 997, 995, 993, 991, 989, 986, 984, 982, 979, 977, 974, 971, 968, 966, 963, 960, 957, 953, 950,
		947, 944, 940, 937, 933, 930, 926, 922, 918, 915, 911, 907, 903, 899, 895, 890, 886, 882, 877, 873, 869, 864, 859, 855, 850, 845, 841, 836, 831, 826, 821, 816, 811,
		806, 801, 795, 790, 785, 779, 774, 769, 763, 758, 752, 747, 741, 735, 730, 724, 718, 712, 707, 701, 695, 689, 683, 677, 671, 665, 659, 653, 647, 641, 635, 629, 623,
		617, 610, 604, 598, 592, 586, 579, 573, 567, 561, 554, 548, 542, 536, 529, 523, 517, 510, 504, 498, 492, 485, 479, 473, 466, 460, 454, 448, 441, 435, 429, 423, 417,
		410, 404, 398, 392, 386, 380, 374, 368, 362, 356, 350, 344, 338, 332, 326, 320, 314, 309, 303, 297, 291, 286, 280, 275, 269, 264, 258, 253, 247, 242, 236, 231, 226,
		221, 216, 211, 205, 200, 195, 191, 186, 181, 176, 171, 167, 162, 157, 153, 149, 144, 140, 135, 131, 127, 123, 119, 115, 111, 107, 103, 99, 96, 92, 89, 85, 82, 78, 75, 72, 69
};

uint16_t Sine_LUT_P3[NS] = {
		954, 951, 948, 945, 941, 938, 934, 931, 927, 924, 920, 916, 912, 908, 904, 900, 896, 892, 888, 883, 879, 874, 870, 866, 861, 856, 852, 847, 842, 837,
		832, 828, 823, 818, 812, 807, 802, 797, 792, 787, 781, 776, 770, 765, 759, 754, 748, 743, 737, 732, 726, 720, 714, 709, 703, 697, 691, 685, 679, 673,
		667, 661, 655, 649, 643, 637, 631, 625, 619, 613, 606, 600, 594, 588, 582, 575, 569, 563, 557, 550, 544, 538, 531, 525, 519, 513, 506, 500, 494, 487,
		481, 475, 469, 462, 456, 450, 444, 437, 431, 425, 419, 413, 406, 400, 394, 388, 382, 376, 370, 364, 358, 352, 346, 340, 334, 328, 322, 316, 311, 305,
		299, 293, 288, 282, 276, 271, 265, 260, 254, 249, 244, 238, 233, 228, 222, 217, 212, 207, 202, 197, 192, 187, 182, 178, 173, 168, 164, 159, 154, 150,
		146, 141, 137, 133, 128, 124, 120, 116, 112, 108, 105, 101, 97, 93, 90, 86, 83, 79, 76, 73, 70, 66, 63, 60, 57, 55, 52, 49, 46, 44, 41, 39, 37, 34, 32,
		30, 28, 26, 24, 22, 20, 18, 17, 15, 14, 12, 11, 10, 9, 7, 6, 5, 5, 4, 3, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10,
		11, 13, 14, 16, 17, 19, 20, 22, 24, 26, 28, 30, 32, 35, 37, 39, 42, 44, 47, 50, 52, 55, 58, 61, 64, 67, 70, 73, 77, 80, 83, 87, 90, 94, 98, 101, 105,
		109, 113, 117, 121, 125, 129, 133, 138, 142, 146, 151, 155, 160, 164, 169, 174, 178, 183, 188, 193, 198, 203, 208, 213, 218, 223, 229, 234, 239, 244,
		250, 255, 261, 266, 272, 277, 283, 289, 294, 300, 306, 312, 317, 323, 329, 335, 341, 347, 353, 359, 365, 371, 377, 383, 389, 395, 401, 407, 414, 420,
		426, 432, 438, 445, 451, 457, 463, 470, 476, 482, 488, 495, 501, 507, 514, 520, 526, 532, 539, 545, 551, 558, 564, 570, 576, 583, 589, 595, 601, 607,
		614, 620, 626, 632, 638, 644, 650, 656, 662, 668, 674, 680, 686, 692, 698, 704, 710, 715, 721, 727, 732, 738, 744, 749, 755, 760, 766, 771, 777, 782,
		787, 793, 798, 803, 808, 813, 818, 823, 828, 833, 838, 843, 848, 852, 857, 862, 866, 871, 875, 880, 884, 888, 892, 897, 901, 905, 909, 913, 917, 920,
		924, 928, 931, 935, 938, 942, 945, 949, 952, 955, 958, 961, 964, 967, 970, 973, 975, 978, 980, 983, 985, 988, 990, 992, 994, 996, 998, 1000, 1002, 1004,
		1005, 1007, 1008, 1010, 1011, 1013, 1014, 1015, 1016, 1017, 1018, 1019, 1020, 1020, 1021, 1021, 1022, 1022, 1023, 1023, 1023, 1023, 1023, 1023, 1023,
		1023, 1022, 1022, 1021, 1021, 1020, 1019, 1019, 1018, 1017, 1016, 1015, 1014, 1012, 1011, 1010, 1008, 1007, 1005, 1003, 1002, 1000, 998, 996, 994, 992,
		990, 987, 985, 982, 980, 977, 975, 972, 969, 967, 964, 961, 958, 954
};
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
 ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

/* USER CODE BEGIN PV */
uint32_t F_SINE = 500;
uint32_t ADC_Value = 0;
uint32_t new_freq = 0;
uint32_t TIM1_Tick = 0;

uint16_t index_LUT = 0;


float Soft_Start = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM1_Init(void);
static void MX_DMA_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM2_Init(void);
static void MX_TIM3_Init(void);
/* USER CODE BEGIN PFP */
void Update_TIM1_ARR(TIM_HandleTypeDef* htim, uint16_t new_arr) {
	__HAL_TIM_SET_AUTORELOAD(htim, new_arr);

	if (__HAL_TIM_GET_COUNTER(htim) >= __HAL_TIM_GET_AUTORELOAD(htim))
		htim->Instance->EGR |= TIM_EGR_UG;
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM1)
	{
		TIM2->CCR1 = Sine_LUT_P1[index_LUT]*Soft_Start;
		TIM2->CCR2 = Sine_LUT_P2[index_LUT]*Soft_Start;
		TIM2->CCR3 = Sine_LUT_P3[index_LUT]*Soft_Start;
		//__HAL_TIM_SetCompare();
		if (index_LUT < 512) index_LUT++;
		else index_LUT = 0;
	}
	if (htim->Instance == TIM3)
	{
		HAL_TIM_Base_Stop_IT(&htim1);
		F_SINE = (uint32_t) 100 + ADC_Value*400/4095;
		TIM1_Tick  = TIMER1_CLk / (NS*F_SINE);
		Update_TIM1_ARR(&htim1, (uint16_t) TIM1_Tick - 1);
		HAL_TIM_Base_Start_IT(&htim1);
	}
}

void Soft_Start_Function()
{
	while (Soft_Start <= 1.0)
		Soft_Start = Soft_Start+ 0.01;
	HAL_Delay(400);

}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM1_Init();
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
  TIM1_Tick  = TIMER1_CLk / (NS*F_SINE);
  Soft_Start = 1.0;
  Update_TIM1_ARR(&htim1, (uint16_t) TIM1_Tick - 1);
  HAL_TIM_Base_Start_IT(&htim1);
  HAL_TIM_Base_Start_IT(&htim3);
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
  HAL_ADC_Start_DMA(&hadc1, &ADC_Value, 1);
//  Soft_Start_Function();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
//	  F_SINE = (uint32_t) 100 + ADC_Value*900/4095;
//	  TIM1_Tick  = TIMER1_CLk / (NS*F_SINE);
//	  Update_TIM1_ARR(&htim1, (uint16_t) TIM1_Tick - 1);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 400;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 4;
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = ENABLE;
  hadc1.Init.ContinuousConvMode = ENABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = ENABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SEQ_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_84CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 0;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 2;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 1023;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 1000;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 60000;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA2_Stream0_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

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
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
