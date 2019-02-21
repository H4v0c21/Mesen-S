#pragma once
#include "stdafx.h"

class Console;
struct SNES_SPC;

class Spc
{
private:
	static constexpr int SampleBufferSize = 0x100000;

	shared_ptr<Console> _console;
	uint8_t _spcBios[64];
	SNES_SPC* _spc;
	int16_t *_soundBuffer;
	uint64_t _startFrameMasterClock = 0;

	int GetSpcTime();

public:
	Spc(shared_ptr<Console> console);
	~Spc();

	uint8_t Read(uint16_t addr);
	void Write(uint32_t addr, uint8_t value);

	void ProcessEndFrame();
};