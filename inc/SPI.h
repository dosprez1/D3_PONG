/*
 * SPI.h
 *
 *  Created on: 20 apr. 2017
 *      Author: Acer
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_

#include <Stream.h>
#include <Vector.h>
#include <config_file.h>
#include <stm32f4xx_conf.h>

class SPI : Stream {
public:
							SPI();
	virtual 				~SPI();

public:
	virtual void			write(uint16_t data);
	virtual const uint16_t	read();

public:
	virtual const uint16_t	getBufferLenght() const;

#if SPI_INTERRUPT_ENABLE
public:
	virtual void			interruptRead();
	static SPI				sInstance;

private:
	void 					SPIinterruptConfig(NVIC_InitTypeDef NVIC_InitStructure);

#endif

private:
	Vector<uint16_t>		m_buffer;

	void 					GPIOinit(GPIO_InitTypeDef GPIO_InitStructure);
	void 					GPIOconfig();
	void 					SPIinit(SPI_InitTypeDef SPI_InitStructure);
};

#ifdef __cplusplus
extern "C" {
#endif
#if SPI_INTERRUPT_ENABLE

void SPI2_IRQHandler();

#endif /* SPI_INTERRUPT_ENABLE */
#ifdef __cplusplus
}
#endif
#endif /* INC_SPI_H_ */
