//Реализация системы запуска ПК по кнопке. Упрощено до невозможности. Пользовательнь запускает ПК через данный ему интерфейс кнопки,
//для чего пользователю не нужно знать, что происходит под капотом процесса, что в свою очередь реализует паттерн фасад. 
#include <iostream>
#include <Windows.h>

using namespace std;

#define ITTERATION_COUNT 20

class MotherBoard
{
public:
	void MthrBrdPwrOn()
	{
		cout << "MotherBoard Online. Trying to boot:" << endl;
	}
};

class CPU
{
public:
	void CpuPwrOn()
	{
		cout << "1. CPU";
		for (int i = 0; i < ITTERATION_COUNT; i++)
		{
			cout << ".";
			Sleep(250);
		}
		cout << "Online" << endl;
	}
};

class Storage
{
public:
	void StrgPwrOn()
	{
		cout << "3. Harddrive";
		for (int i = 0; i < (ITTERATION_COUNT-6); i++)
		{
			cout << ".";
			Sleep(250);
		}
		cout << "Online" << endl;
	}
};

class RAM
{
public:
	void RamPwrOn()
	{
		cout << "2. RAM";
		for (int i = 0; i < ITTERATION_COUNT; i++)
		{
			cout << ".";
			Sleep(250);
		}
		cout << "Online" << endl;
	}
};

class PowerButton
{
	MotherBoard motherboard;
	CPU cpu;
	RAM ram;
	Storage harddrive;
public:
	void PwrOn()
	{
		cout << "Power Button pressed" << endl;
		Sleep(1500);
		motherboard.MthrBrdPwrOn();
		cpu.CpuPwrOn();
		ram.RamPwrOn();
		harddrive.StrgPwrOn();
		Sleep(1500);
		cout << "Your PC is on, enjoy!" << endl;
	}

};

void main()
{
	setlocale(LC_ALL, "");

	PowerButton pwrbttn;
	pwrbttn.PwrOn();

}