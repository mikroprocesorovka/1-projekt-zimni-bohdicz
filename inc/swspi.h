//DIN PB5, CS PB4, CLKPB3

#define DIN_GPIO GPIOD
#define DIN_PIN GPIO_PIN_6
#define CS_GPIO GPIOD
#define CS_PIN GPIO_PIN_5
#define CLK_GPIO GPIOE
#define CLK_PIN GPIO_PIN_0

//za #define za XXX se dosadí YYY z tohoto souboru

void swspi_init(void);
void swspi_tx16(uint16_t data);
void swspi_adressXdata(uint8_t adress, uint8_t data);
void swspi_send_number(uint32_t number);
void swspi_send_time (uint8_t seconds,uint8_t minutes, uint8_t hours);
void swspi_toggle(uint8_t rad, uint8_t hodnota_radu);
void swspi_toggle_slowly(uint8_t rad, uint8_t hodnota_radu);
