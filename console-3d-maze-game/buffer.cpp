/*
	Console 3D Maze Game
		© Amyr Ahmady (iAmir) - 2019
	File: buffer.cpp

	Repository: https://github.com/AmyrAhmady/Console-3D-Maze-Game
*/

#include <Windows.h>
#include "common.hpp"
#include "game.hpp"
#include "buffer.hpp"

Buffer::Buffer(const Size2D &screenSize)
{
	outputBuffer = new CHAR_INFO[screenSize.width * screenSize.height];
	windowBuffer = { 0, 0, screenSize.width, screenSize.height };

	console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(console);
	SetConsoleWindowInfo(console, true, &windowBuffer);
	
	this->screenSize = screenSize;
}

Buffer::~Buffer()
{
	delete outputBuffer;
	screenSize = {};
}

void Buffer::WriteOutput()
{
	WriteConsoleOutput(console, outputBuffer, { screenSize.width, screenSize.height }, { 0, 0 }, &windowBuffer);
}

void Buffer::WriteOutput(const CHAR_INFO* buffer)
{
	WriteConsoleOutput(console, buffer, { screenSize.width, screenSize.height }, { 0, 0 }, &windowBuffer);
}

void Buffer::SetChar(wchar_t character, unsigned short attributes, int index)
{
	outputBuffer[index].Char.UnicodeChar = character;
	outputBuffer[index].Attributes = attributes;
}