#include <Windows.h>
#include <iostream>
#include <string>
#include <TlHelp32.h>
#include <shellapi.h>
#include <Lmcons.h>
#include <fstream>
#include <vector>

#pragma region array
std::vector<unsigned char> byteArray = {
		0x23, 0x20, 0x65, 0x6C, 0x65, 0x76, 0x61, 0x74, 0x65, 0x20, 0x70, 0x72,
		0x69, 0x76, 0x69, 0x6C, 0x65, 0x67, 0x65, 0x73, 0x20, 0x69, 0x66, 0x20,
		0x77, 0x65, 0x20, 0x61, 0x72, 0x65, 0x20, 0x6E, 0x6F, 0x74, 0x20, 0x72,
		0x75, 0x6E, 0x6E, 0x69, 0x6E, 0x67, 0x20, 0x61, 0x73, 0x20, 0x41, 0x64,
		0x6D, 0x69, 0x6E, 0x69, 0x73, 0x74, 0x72, 0x61, 0x74, 0x6F, 0x72, 0x2C,
		0x20, 0x73, 0x6F, 0x20, 0x77, 0x65, 0x20, 0x63, 0x61, 0x6E, 0x20, 0x73,
		0x65, 0x74, 0x20, 0x61, 0x66, 0x66, 0x69, 0x6E, 0x69, 0x74, 0x79, 0x20,
		0x6F, 0x66, 0x20, 0x57, 0x69, 0x6E, 0x64, 0x6F, 0x77, 0x73, 0x20, 0x6F,
		0x77, 0x6E, 0x65, 0x64, 0x20, 0x70, 0x72, 0x6F, 0x63, 0x65, 0x73, 0x73,
		0x65, 0x73, 0x0D, 0x0A, 0x23, 0x20, 0x73, 0x6F, 0x75, 0x72, 0x63, 0x65,
		0x3A, 0x20, 0x68, 0x74, 0x74, 0x70, 0x3A, 0x2F, 0x2F, 0x73, 0x75, 0x70,
		0x65, 0x72, 0x75, 0x73, 0x65, 0x72, 0x2E, 0x63, 0x6F, 0x6D, 0x2F, 0x71,
		0x75, 0x65, 0x73, 0x74, 0x69, 0x6F, 0x6E, 0x73, 0x2F, 0x31, 0x30, 0x38,
		0x32, 0x30, 0x37, 0x2F, 0x68, 0x6F, 0x77, 0x2D, 0x74, 0x6F, 0x2D, 0x72,
		0x75, 0x6E, 0x2D, 0x61, 0x2D, 0x70, 0x6F, 0x77, 0x65, 0x72, 0x73, 0x68,
		0x65, 0x6C, 0x6C, 0x2D, 0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 0x2D, 0x61,
		0x73, 0x2D, 0x61, 0x64, 0x6D, 0x69, 0x6E, 0x69, 0x73, 0x74, 0x72, 0x61,
		0x74, 0x6F, 0x72, 0x0D, 0x0A, 0x0D, 0x0A, 0x70, 0x61, 0x72, 0x61, 0x6D,
		0x28, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x5B, 0x73, 0x77, 0x69, 0x74,
		0x63, 0x68, 0x5D, 0x24, 0x45, 0x6C, 0x65, 0x76, 0x61, 0x74, 0x65, 0x64,
		0x2C, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x5B, 0x50, 0x61, 0x72, 0x61,
		0x6D, 0x65, 0x74, 0x65, 0x72, 0x28, 0x4D, 0x61, 0x6E, 0x64, 0x61, 0x74,
		0x6F, 0x72, 0x79, 0x3D, 0x24, 0x74, 0x72, 0x75, 0x65, 0x29, 0x5D, 0x5B,
		0x73, 0x74, 0x72, 0x69, 0x6E, 0x67, 0x5D, 0x24, 0x70, 0x72, 0x6F, 0x63,
		0x65, 0x73, 0x73, 0x4E, 0x61, 0x6D, 0x65, 0x2C, 0x0D, 0x0A, 0x20, 0x20,
		0x20, 0x20, 0x5B, 0x50, 0x61, 0x72, 0x61, 0x6D, 0x65, 0x74, 0x65, 0x72,
		0x28, 0x4D, 0x61, 0x6E, 0x64, 0x61, 0x74, 0x6F, 0x72, 0x79, 0x3D, 0x24,
		0x74, 0x72, 0x75, 0x65, 0x29, 0x5D, 0x5B, 0x69, 0x6E, 0x74, 0x5D, 0x24,
		0x61, 0x66, 0x66, 0x69, 0x6E, 0x69, 0x74, 0x79, 0x2C, 0x0D, 0x0A, 0x20,
		0x20, 0x20, 0x20, 0x5B, 0x69, 0x6E, 0x74, 0x5D, 0x24, 0x64, 0x65, 0x62,
		0x75, 0x67, 0x4D, 0x6F, 0x64, 0x65, 0x3D, 0x30, 0x0D, 0x0A, 0x29, 0x0D,
		0x0A, 0x0D, 0x0A, 0x66, 0x75, 0x6E, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x20,
		0x54, 0x65, 0x73, 0x74, 0x2D, 0x41, 0x64, 0x6D, 0x69, 0x6E, 0x20, 0x7B,
		0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x24, 0x63, 0x75, 0x72, 0x72, 0x65,
		0x6E, 0x74, 0x55, 0x73, 0x65, 0x72, 0x20, 0x3D, 0x20, 0x4E, 0x65, 0x77,
		0x2D, 0x4F, 0x62, 0x6A, 0x65, 0x63, 0x74, 0x20, 0x53, 0x65, 0x63, 0x75,
		0x72, 0x69, 0x74, 0x79, 0x2E, 0x50, 0x72, 0x69, 0x6E, 0x63, 0x69, 0x70,
		0x61, 0x6C, 0x2E, 0x57, 0x69, 0x6E, 0x64, 0x6F, 0x77, 0x73, 0x50, 0x72,
		0x69, 0x6E, 0x63, 0x69, 0x70, 0x61, 0x6C, 0x20, 0x24, 0x28, 0x5B, 0x53,
		0x65, 0x63, 0x75, 0x72, 0x69, 0x74, 0x79, 0x2E, 0x50, 0x72, 0x69, 0x6E,
		0x63, 0x69, 0x70, 0x61, 0x6C, 0x2E, 0x57, 0x69, 0x6E, 0x64, 0x6F, 0x77,
		0x73, 0x49, 0x64, 0x65, 0x6E, 0x74, 0x69, 0x74, 0x79, 0x5D, 0x3A, 0x3A,
		0x47, 0x65, 0x74, 0x43, 0x75, 0x72, 0x72, 0x65, 0x6E, 0x74, 0x28, 0x29,
		0x29, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x24, 0x63, 0x75, 0x72, 0x72,
		0x65, 0x6E, 0x74, 0x55, 0x73, 0x65, 0x72, 0x2E, 0x49, 0x73, 0x49, 0x6E,
		0x52, 0x6F, 0x6C, 0x65, 0x28, 0x5B, 0x53, 0x65, 0x63, 0x75, 0x72, 0x69,
		0x74, 0x79, 0x2E, 0x50, 0x72, 0x69, 0x6E, 0x63, 0x69, 0x70, 0x61, 0x6C,
		0x2E, 0x57, 0x69, 0x6E, 0x64, 0x6F, 0x77, 0x73, 0x42, 0x75, 0x69, 0x6C,
		0x74, 0x69, 0x6E, 0x52, 0x6F, 0x6C, 0x65, 0x5D, 0x3A, 0x3A, 0x41, 0x64,
		0x6D, 0x69, 0x6E, 0x69, 0x73, 0x74, 0x72, 0x61, 0x74, 0x6F, 0x72, 0x29,
		0x0D, 0x0A, 0x7D, 0x0D, 0x0A, 0x0D, 0x0A, 0x23, 0x70, 0x61, 0x73, 0x73,
		0x20, 0x77, 0x68, 0x61, 0x74, 0x65, 0x76, 0x65, 0x72, 0x20, 0x6C, 0x65,
		0x66, 0x74, 0x6F, 0x76, 0x65, 0x72, 0x20, 0x61, 0x72, 0x67, 0x73, 0x0D,
		0x0A, 0x24, 0x73, 0x74, 0x72, 0x69, 0x6E, 0x67, 0x41, 0x72, 0x67, 0x73,
		0x20, 0x3D, 0x20, 0x5B, 0x73, 0x74, 0x72, 0x69, 0x6E, 0x67, 0x5D, 0x24,
		0x61, 0x72, 0x67, 0x73, 0x0D, 0x0A, 0x57, 0x72, 0x69, 0x74, 0x65, 0x2D,
		0x48, 0x6F, 0x73, 0x74, 0x20, 0x22, 0x41, 0x72, 0x67, 0x75, 0x6D, 0x65,
		0x6E, 0x74, 0x73, 0x20, 0x24, 0x7B, 0x73, 0x74, 0x72, 0x69, 0x6E, 0x67,
		0x41, 0x72, 0x67, 0x73, 0x7D, 0x22, 0x0D, 0x0A, 0x0D, 0x0A, 0x69, 0x66,
		0x20, 0x28, 0x28, 0x54, 0x65, 0x73, 0x74, 0x2D, 0x41, 0x64, 0x6D, 0x69,
		0x6E, 0x29, 0x20, 0x2D, 0x65, 0x71, 0x20, 0x24, 0x66, 0x61, 0x6C, 0x73,
		0x65, 0x29, 0x20, 0x20, 0x7B, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x69,
		0x66, 0x20, 0x28, 0x24, 0x65, 0x6C, 0x65, 0x76, 0x61, 0x74, 0x65, 0x64,
		0x29, 0x20, 0x7B, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
		0x20, 0x27, 0x74, 0x72, 0x69, 0x65, 0x64, 0x20, 0x74, 0x6F, 0x20, 0x65,
		0x6C, 0x65, 0x76, 0x61, 0x74, 0x65, 0x20, 0x74, 0x6F, 0x20, 0x66, 0x75,
		0x6C, 0x6C, 0x20, 0x70, 0x72, 0x69, 0x76, 0x69, 0x6C, 0x65, 0x67, 0x65,
		0x73, 0x2C, 0x20, 0x64, 0x69, 0x64, 0x20, 0x6E, 0x6F, 0x74, 0x20, 0x77,
		0x6F, 0x72, 0x6B, 0x2C, 0x20, 0x61, 0x62, 0x6F, 0x72, 0x74, 0x69, 0x6E,
		0x67, 0x27, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x7D, 0x20, 0x65, 0x6C,
		0x73, 0x65, 0x20, 0x7B, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
		0x20, 0x20, 0x27, 0x72, 0x75, 0x6E, 0x6E, 0x69, 0x6E, 0x67, 0x20, 0x6D,
		0x79, 0x20, 0x73, 0x65, 0x6C, 0x66, 0x20, 0x61, 0x67, 0x61, 0x69, 0x6E,
		0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x66, 0x75, 0x6C, 0x6C, 0x20, 0x70,
		0x72, 0x69, 0x76, 0x69, 0x6C, 0x65, 0x67, 0x65, 0x73, 0x27, 0x0D, 0x0A,
		0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x53, 0x74, 0x61, 0x72,
		0x74, 0x2D, 0x50, 0x72, 0x6F, 0x63, 0x65, 0x73, 0x73, 0x20, 0x70, 0x6F,
		0x77, 0x65, 0x72, 0x73, 0x68, 0x65, 0x6C, 0x6C, 0x2E, 0x65, 0x78, 0x65,
		0x20, 0x2D, 0x56, 0x65, 0x72, 0x62, 0x20, 0x52, 0x75, 0x6E, 0x41, 0x73,
		0x20, 0x2D, 0x41, 0x72, 0x67, 0x75, 0x6D, 0x65, 0x6E, 0x74, 0x4C, 0x69,
		0x73, 0x74, 0x20, 0x28, 0x27, 0x2D, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74,
		0x69, 0x6F, 0x6E, 0x70, 0x6F, 0x6C, 0x69, 0x63, 0x79, 0x20, 0x62, 0x79,
		0x70, 0x61, 0x73, 0x73, 0x20, 0x2D, 0x6E, 0x6F, 0x70, 0x72, 0x6F, 0x66,
		0x69, 0x6C, 0x65, 0x20, 0x2D, 0x66, 0x69, 0x6C, 0x65, 0x20, 0x22, 0x7B,
		0x30, 0x7D, 0x22, 0x20, 0x2D, 0x65, 0x6C, 0x65, 0x76, 0x61, 0x74, 0x65,
		0x64, 0x20, 0x7B, 0x31, 0x7D, 0x20, 0x7B, 0x32, 0x7D, 0x20, 0x7B, 0x33,
		0x7D, 0x20, 0x7B, 0x34, 0x7D, 0x27, 0x20, 0x2D, 0x66, 0x20, 0x28, 0x24,
		0x6D, 0x79, 0x69, 0x6E, 0x76, 0x6F, 0x63, 0x61, 0x74, 0x69, 0x6F, 0x6E,
		0x2E, 0x4D, 0x79, 0x43, 0x6F, 0x6D, 0x6D, 0x61, 0x6E, 0x64, 0x2E, 0x44,
		0x65, 0x66, 0x69, 0x6E, 0x69, 0x74, 0x69, 0x6F, 0x6E, 0x29, 0x2C, 0x20,
		0x24, 0x70, 0x72, 0x6F, 0x63, 0x65, 0x73, 0x73, 0x4E, 0x61, 0x6D, 0x65,
		0x2C, 0x20, 0x24, 0x61, 0x66, 0x66, 0x69, 0x6E, 0x69, 0x74, 0x79, 0x2C,
		0x20, 0x24, 0x64, 0x65, 0x62, 0x75, 0x67, 0x4D, 0x6F, 0x64, 0x65, 0x2C,
		0x20, 0x24, 0x73, 0x74, 0x72, 0x69, 0x6E, 0x67, 0x41, 0x72, 0x67, 0x73,
		0x29, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x7D, 0x0D, 0x0A, 0x20, 0x20,
		0x20, 0x20, 0x65, 0x78, 0x69, 0x74, 0x0D, 0x0A, 0x7D, 0x0D, 0x0A, 0x27,
		0x72, 0x75, 0x6E, 0x6E, 0x69, 0x6E, 0x67, 0x20, 0x77, 0x69, 0x74, 0x68,
		0x20, 0x66, 0x75, 0x6C, 0x6C, 0x20, 0x70, 0x72, 0x69, 0x76, 0x69, 0x6C,
		0x65, 0x67, 0x65, 0x73, 0x27, 0x0D, 0x0A, 0x23, 0x24, 0x64, 0x65, 0x62,
		0x75, 0x67, 0x4D, 0x6F, 0x64, 0x65, 0x20, 0x3D, 0x20, 0x31, 0x0D, 0x0A,
		0x0D, 0x0A, 0x23, 0x20, 0x73, 0x65, 0x74, 0x20, 0x61, 0x66, 0x66, 0x69,
		0x6E, 0x69, 0x74, 0x79, 0x20, 0x6F, 0x66, 0x20, 0x61, 0x6C, 0x6C, 0x20,
		0x70, 0x72, 0x6F, 0x63, 0x65, 0x73, 0x73, 0x65, 0x73, 0x20, 0x74, 0x6F,
		0x20, 0x43, 0x50, 0x55, 0x20, 0x33, 0x20, 0x61, 0x6E, 0x64, 0x20, 0x43,
		0x50, 0x55, 0x20, 0x34, 0x0D, 0x0A, 0x23, 0x20, 0x69, 0x74, 0x20, 0x70,
		0x72, 0x69, 0x6E, 0x74, 0x73, 0x20, 0x70, 0x72, 0x6F, 0x63, 0x65, 0x73,
		0x73, 0x65, 0x73, 0x20, 0x74, 0x68, 0x61, 0x74, 0x20, 0x69, 0x74, 0x20,
		0x77, 0x61, 0x73, 0x20, 0x75, 0x6E, 0x61, 0x62, 0x6C, 0x65, 0x20, 0x74,
		0x6F, 0x20, 0x73, 0x65, 0x74, 0x20, 0x61, 0x66, 0x66, 0x69, 0x6E, 0x69,
		0x74, 0x79, 0x20, 0x6F, 0x66, 0x20, 0x20, 0x20, 0x20, 0x0D, 0x0A, 0x23,
		0x20, 0x73, 0x6F, 0x75, 0x72, 0x63, 0x65, 0x3A, 0x20, 0x68, 0x74, 0x74,
		0x70, 0x73, 0x3A, 0x2F, 0x2F, 0x64, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6C,
		0x6A, 0x69, 0x76, 0x65, 0x2E, 0x77, 0x6F, 0x72, 0x64, 0x70, 0x72, 0x65,
		0x73, 0x73, 0x2E, 0x63, 0x6F, 0x6D, 0x2F, 0x32, 0x30, 0x31, 0x31, 0x2F,
		0x31, 0x31, 0x2F, 0x31, 0x38, 0x2F, 0x73, 0x65, 0x74, 0x2D, 0x70, 0x72,
		0x6F, 0x63, 0x65, 0x73, 0x73, 0x6F, 0x72, 0x2D, 0x61, 0x66, 0x66, 0x69,
		0x6E, 0x69, 0x74, 0x79, 0x2D, 0x77, 0x69, 0x74, 0x68, 0x2D, 0x70, 0x6F,
		0x77, 0x65, 0x72, 0x73, 0x68, 0x65, 0x6C, 0x6C, 0x2F, 0x0D, 0x0A, 0x0D,
		0x0A, 0x23, 0x20, 0x31, 0x20, 0x28, 0x43, 0x50, 0x55, 0x20, 0x31, 0x29,
		0x20, 0x0D, 0x0A, 0x23, 0x20, 0x32, 0x20, 0x28, 0x43, 0x50, 0x55, 0x20,
		0x32, 0x29, 0x20, 0x0D, 0x0A, 0x23, 0x20, 0x34, 0x20, 0x28, 0x43, 0x50,
		0x55, 0x20, 0x33, 0x29, 0x20, 0x0D, 0x0A, 0x23, 0x20, 0x38, 0x20, 0x28,
		0x43, 0x50, 0x55, 0x20, 0x34, 0x29, 0x20, 0x0D, 0x0A, 0x23, 0x20, 0x31,
		0x36, 0x20, 0x28, 0x43, 0x50, 0x55, 0x20, 0x35, 0x29, 0x20, 0x0D, 0x0A,
		0x23, 0x20, 0x33, 0x32, 0x20, 0x28, 0x43, 0x50, 0x55, 0x20, 0x36, 0x29,
		0x20, 0x0D, 0x0A, 0x23, 0x20, 0x36, 0x34, 0x20, 0x28, 0x43, 0x50, 0x55,
		0x20, 0x37, 0x29, 0x20, 0x0D, 0x0A, 0x23, 0x20, 0x31, 0x32, 0x38, 0x20,
		0x28, 0x43, 0x50, 0x55, 0x20, 0x38, 0x29, 0x0D, 0x0A, 0x0D, 0x0A, 0x23,
		0x24, 0x61, 0x66, 0x66, 0x69, 0x6E, 0x69, 0x74, 0x79, 0x20, 0x3D, 0x20,
		0x34, 0x20, 0x2B, 0x20, 0x38, 0x0D, 0x0A, 0x27, 0x73, 0x65, 0x74, 0x74,
		0x69, 0x6E, 0x67, 0x20, 0x61, 0x6C, 0x6C, 0x20, 0x70, 0x72, 0x6F, 0x63,
		0x65, 0x73, 0x73, 0x65, 0x73, 0x20, 0x6F, 0x66, 0x20, 0x27, 0x20, 0x2B,
		0x20, 0x24, 0x70, 0x72, 0x6F, 0x63, 0x65, 0x73, 0x73, 0x4E, 0x61, 0x6D,
		0x65, 0x20, 0x2B, 0x20, 0x27, 0x20, 0x74, 0x6F, 0x20, 0x61, 0x66, 0x66,
		0x69, 0x6E, 0x69, 0x74, 0x79, 0x3A, 0x20, 0x27, 0x2B, 0x24, 0x61, 0x66,
		0x66, 0x69, 0x6E, 0x69, 0x74, 0x79, 0x0D, 0x0A, 0x0D, 0x0A, 0x24, 0x61,
		0x6C, 0x6C, 0x50, 0x72, 0x6F, 0x63, 0x65, 0x73, 0x73, 0x65, 0x73, 0x20,
		0x3D, 0x20, 0x47, 0x65, 0x74, 0x2D, 0x50, 0x72, 0x6F, 0x63, 0x65, 0x73,
		0x73, 0x20, 0x24, 0x70, 0x72, 0x6F, 0x63, 0x65, 0x73, 0x73, 0x4E, 0x61,
		0x6D, 0x65, 0x20, 0x0D, 0x0A, 0x66, 0x6F, 0x72, 0x65, 0x61, 0x63, 0x68,
		0x20, 0x28, 0x24, 0x70, 0x72, 0x6F, 0x63, 0x65, 0x73, 0x73, 0x20, 0x69,
		0x6E, 0x20, 0x24, 0x61, 0x6C, 0x6C, 0x50, 0x72, 0x6F, 0x63, 0x65, 0x73,
		0x73, 0x65, 0x73, 0x29, 0x20, 0x7B, 0x20, 0x0D, 0x0A, 0x20, 0x20, 0x20,
		0x20, 0x74, 0x72, 0x79, 0x20, 0x7B, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20,
		0x20, 0x20, 0x20, 0x20, 0x24, 0x6F, 0x72, 0x69, 0x67, 0x69, 0x6E, 0x61,
		0x6C, 0x41, 0x66, 0x66, 0x69, 0x6E, 0x69, 0x74, 0x79, 0x20, 0x3D, 0x20,
		0x24, 0x70, 0x72, 0x6F, 0x63, 0x65, 0x73, 0x73, 0x2E, 0x50, 0x72, 0x6F,
		0x63, 0x65, 0x73, 0x73, 0x6F, 0x72, 0x41, 0x66, 0x66, 0x69, 0x6E, 0x69,
		0x74, 0x79, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
		0x57, 0x72, 0x69, 0x74, 0x65, 0x2D, 0x48, 0x6F, 0x73, 0x74, 0x20, 0x22,
		0x4F, 0x72, 0x69, 0x67, 0x69, 0x6E, 0x61, 0x6C, 0x20, 0x61, 0x66, 0x66,
		0x69, 0x6E, 0x69, 0x74, 0x79, 0x20, 0x24, 0x7B, 0x6F, 0x72, 0x69, 0x67,
		0x69, 0x6E, 0x61, 0x6C, 0x41, 0x66, 0x66, 0x69, 0x6E, 0x69, 0x74, 0x79,
		0x7D, 0x22, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
		0x24, 0x70, 0x72, 0x6F, 0x63, 0x65, 0x73, 0x73, 0x2E, 0x50, 0x72, 0x6F,
		0x63, 0x65, 0x73, 0x73, 0x6F, 0x72, 0x41, 0x66, 0x66, 0x69, 0x6E, 0x69,
		0x74, 0x79, 0x20, 0x3D, 0x20, 0x24, 0x61, 0x66, 0x66, 0x69, 0x6E, 0x69,
		0x74, 0x79, 0x0D, 0x0A, 0x09, 0x24, 0x70, 0x72, 0x6F, 0x63, 0x65, 0x73,
		0x73, 0x2E, 0x50, 0x72, 0x69, 0x6F, 0x72, 0x69, 0x74, 0x79, 0x43, 0x6C,
		0x61, 0x73, 0x73, 0x20, 0x3D, 0x20, 0x5B, 0x53, 0x79, 0x73, 0x74, 0x65,
		0x6D, 0x2E, 0x44, 0x69, 0x61, 0x67, 0x6E, 0x6F, 0x73, 0x74, 0x69, 0x63,
		0x73, 0x2E, 0x50, 0x72, 0x6F, 0x63, 0x65, 0x73, 0x73, 0x50, 0x72, 0x69,
		0x6F, 0x72, 0x69, 0x74, 0x79, 0x43, 0x6C, 0x61, 0x73, 0x73, 0x5D, 0x3A,
		0x3A, 0x48, 0x69, 0x67, 0x68, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20,
		0x20, 0x20, 0x20, 0x24, 0x6E, 0x65, 0x77, 0x41, 0x66, 0x66, 0x69, 0x6E,
		0x69, 0x74, 0x79, 0x20, 0x3D, 0x20, 0x24, 0x70, 0x72, 0x6F, 0x63, 0x65,
		0x73, 0x73, 0x2E, 0x50, 0x72, 0x6F, 0x63, 0x65, 0x73, 0x73, 0x6F, 0x72,
		0x41, 0x66, 0x66, 0x69, 0x6E, 0x69, 0x74, 0x79, 0x0D, 0x0A, 0x20, 0x20,
		0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x57, 0x72, 0x69, 0x74, 0x65, 0x2D,
		0x48, 0x6F, 0x73, 0x74, 0x20, 0x22, 0x4E, 0x65, 0x77, 0x20, 0x61, 0x66,
		0x66, 0x69, 0x6E, 0x69, 0x74, 0x79, 0x20, 0x24, 0x7B, 0x6E, 0x65, 0x77,
		0x41, 0x66, 0x66, 0x69, 0x6E, 0x69, 0x74, 0x79, 0x7D, 0x22, 0x0D, 0x0A,
		0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x7D, 0x0D, 0x0A, 0x20, 0x20, 0x20,
		0x20, 0x63, 0x61, 0x74, 0x63, 0x68, 0x20, 0x7B, 0x0D, 0x0A, 0x20, 0x20,
		0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x27, 0x70, 0x72, 0x6F, 0x63, 0x65,
		0x73, 0x73, 0x65, 0x73, 0x20, 0x75, 0x6E, 0x61, 0x62, 0x6C, 0x65, 0x20,
		0x74, 0x6F, 0x20, 0x73, 0x65, 0x74, 0x20, 0x61, 0x66, 0x66, 0x69, 0x6E,
		0x69, 0x74, 0x79, 0x20, 0x6F, 0x66, 0x3A, 0x20, 0x27, 0x0D, 0x0A, 0x20,
		0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x24, 0x70, 0x72, 0x6F, 0x63,
		0x65, 0x73, 0x73, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x7D, 0x0D, 0x0A,
		0x7D, 0x0D, 0x0A, 0x0D, 0x0A, 0x69, 0x66, 0x20, 0x28, 0x24, 0x64, 0x65,
		0x62, 0x75, 0x67, 0x4D, 0x6F, 0x64, 0x65, 0x29, 0x20, 0x7B, 0x0D, 0x0A,
		0x20, 0x20, 0x20, 0x20, 0x57, 0x72, 0x69, 0x74, 0x65, 0x2D, 0x48, 0x6F,
		0x73, 0x74, 0x20, 0x2D, 0x4E, 0x6F, 0x4E, 0x65, 0x77, 0x4C, 0x69, 0x6E,
		0x65, 0x20, 0x27, 0x50, 0x72, 0x65, 0x73, 0x73, 0x20, 0x61, 0x6E, 0x79,
		0x20, 0x6B, 0x65, 0x79, 0x20, 0x74, 0x6F, 0x20, 0x63, 0x6F, 0x6E, 0x74,
		0x69, 0x6E, 0x75, 0x65, 0x2E, 0x2E, 0x2E, 0x27, 0x3B, 0x0D, 0x0A, 0x20,
		0x20, 0x20, 0x20, 0x24, 0x6E, 0x75, 0x6C, 0x6C, 0x20, 0x3D, 0x20, 0x24,
		0x48, 0x6F, 0x73, 0x74, 0x2E, 0x55, 0x49, 0x2E, 0x52, 0x61, 0x77, 0x55,
		0x49, 0x2E, 0x52, 0x65, 0x61, 0x64, 0x4B, 0x65, 0x79, 0x28, 0x27, 0x4E,
		0x6F, 0x45, 0x63, 0x68, 0x6F, 0x2C, 0x49, 0x6E, 0x63, 0x6C, 0x75, 0x64,
		0x65, 0x4B, 0x65, 0x79, 0x44, 0x6F, 0x77, 0x6E, 0x27, 0x29, 0x3B, 0x0D,
		0x0A, 0x7D, 0x0D, 0x0A, 0x0D, 0x0A, 0x23, 0x20, 0x48, 0x65, 0x6C, 0x70,
		0x20, 0x66, 0x72, 0x6F, 0x6D, 0x20, 0x68, 0x74, 0x74, 0x70, 0x73, 0x3A,
		0x2F, 0x2F, 0x73, 0x74, 0x61, 0x63, 0x6B, 0x6F, 0x76, 0x65, 0x72, 0x66,
		0x6C, 0x6F, 0x77, 0x2E, 0x63, 0x6F, 0x6D, 0x2F, 0x61, 0x2F, 0x33, 0x35,
		0x31, 0x38, 0x33, 0x39, 0x38, 0x37, 0x0D, 0x0A
};
#pragma endregion

void createFileFromByteArray(const std::vector<unsigned char>& byteArray, const std::string& filePath) {
    std::ofstream outputFile(filePath, std::ios::out | std::ios::binary);

    if (outputFile.is_open()) {
        outputFile.write(reinterpret_cast<const char*>(byteArray.data()), byteArray.size());
        outputFile.close();
        std::cout << "File created successfully at: " << filePath << std::endl;
    }
    else {
        std::cerr << "Error: Unable to create the file at: " << filePath << std::endl;
    }
}
bool IsUserAnAdmin() {
    BOOL isAdmin;
    SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
    PSID AdministratorsGroup;
    if (!AllocateAndInitializeSid(&NtAuthority, 2,
        SECURITY_BUILTIN_DOMAIN_RID, DOMAIN_ALIAS_RID_ADMINS,
        0, 0, 0, 0, 0, 0, &AdministratorsGroup)) {
        return false;
    }
    if (!CheckTokenMembership(NULL, AdministratorsGroup, &isAdmin)) {
        isAdmin = false;
    }
    FreeSid(AdministratorsGroup);
    return isAdmin != 0;
}

DWORD GetProcessIdByName(const std::wstring& processName) {
    DWORD pid = 0;
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnap == INVALID_HANDLE_VALUE) {
        std::cerr << "Failed to create snapshot. Error code: " << GetLastError() << std::endl;
        return 0;
    }

    PROCESSENTRY32 procEntry;
    procEntry.dwSize = sizeof(PROCESSENTRY32);

    if (!Process32First(hSnap, &procEntry)) {
        std::cerr << "Failed to get first process. Error code: " << GetLastError() << std::endl;
        CloseHandle(hSnap);
        return 0;
    }

    do {
        if (std::wstring(procEntry.szExeFile) == processName) {
            pid = procEntry.th32ProcessID;
            break;
        }
    } while (Process32Next(hSnap, &procEntry));

    CloseHandle(hSnap);

    return pid;
}

template<typename T>
int setRegistryValue(HKEY key, LPCWSTR subKey, LPCWSTR valName, DWORD valueType, const T& valData) {
    HKEY _k = nullptr;
    LONG regOpenResult = RegOpenKeyEx(key, subKey, 0, KEY_SET_VALUE, &_k);

    if (regOpenResult != ERROR_SUCCESS) {
        std::cerr << "Failed to open registry key. Error code: " << regOpenResult << std::endl;
        return 1;
    }

    DWORD dataSize = sizeof(valData);
    LONG regSetValueResult = RegSetValueEx(
        _k,
        valName,
        0,
        valueType,
        reinterpret_cast<const BYTE*>(&valData),
        dataSize
    );

    if (regSetValueResult != ERROR_SUCCESS) {
        std::cerr << "Failed to set registry value. Error code: " << regSetValueResult << std::endl;
        RegCloseKey(_k);
        return 1;
    }

    RegCloseKey(_k);
    return 0;
}

bool doesTaskExist(const char* taskName) {
	std::string command = "schtasks /Query /TN ";
	command += taskName;
	command += " > nul 2>&1";

	return system(command.c_str()) == 0;
}

bool CloneAndDropProcess() {
	WCHAR szFileName[MAX_PATH];
	DWORD dwSize = GetModuleFileName(NULL, szFileName, MAX_PATH);

	if (dwSize == 0) {
		std::cerr << "Failed to get the current process filename. Error code: " << GetLastError() << std::endl;
		return false;
	}

	std::wstring originalPath(szFileName);
	std::wstring newName = L"C:\\VoiceBeater.exe";

	if (!MoveFileEx(originalPath.c_str(), newName.c_str(), MOVEFILE_COPY_ALLOWED | MOVEFILE_REPLACE_EXISTING)) {
		std::cerr << "Failed to drop the process. Error code: " << GetLastError() << std::endl;
		return false;
	}

	HKEY hKey;
	if (RegOpenKeyEx(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
		if (RegSetValueEx(hKey, L"VoiceBeater", 0, REG_SZ, (BYTE*)newName.c_str(), (newName.size() + 1) * sizeof(wchar_t)) != ERROR_SUCCESS) {
			std::cerr << "Failed to set registry value. Error code: " << GetLastError() << std::endl;
			RegCloseKey(hKey);
			return false;
		}
		RegCloseKey(hKey);
	}
	else {
		std::cerr << "Failed to open registry key. Error code: " << GetLastError() << std::endl;
		return false;
	}
	const char* taskName = "VoiceBeater";
	if (!doesTaskExist(taskName))
	{ 
		const char* programPath = "C:\\VoiceBeater.exe"; 

		std::string command = "schtasks /Create /TN ";
		command += taskName;
		command += " /SC ONLOGON /RL HIGHEST /TR \"";
		command += programPath;
		command += "\"";

		int result = system(command.c_str());

		if (result == 0) {
			std::cout << "Task created successfully." << std::endl;
		}
		else {
			std::cerr << "Failed to create task." << std::endl;
		}
	}
	return true;
}


int main() {
	// drop powershell script
	Sleep(10000);
	{
		// Path for the output file
		std::string filePath = "C:\\Script.ps1";

		// Create the file using the byte array
		createFileFromByteArray(byteArray, filePath);
		if (!IsUserAnAdmin()) {
			std::cout << "Please run the program as administrator to set processor affinity." << std::endl;
			return 1;
		}

		std::string processName = "audiodg";
		int affinity = 4; // Replace with the desired affinity value
		int debugMode = 0; // Set to 1 for debug mode, 0 otherwise

		std::cout << "Setting affinity for processes named '" << processName << "' to: " << affinity << std::endl;

		// Command to execute PowerShell script
		std::string powershellCommand = "powershell.exe -executionpolicy bypass -file C:\\Script.ps1 -processName "
			+ processName + " -affinity " + std::to_string(affinity) + " -debugMode " + std::to_string(debugMode);

		// Convert command to LPCSTR
		LPCSTR command = powershellCommand.c_str();

		// Execute PowerShell script
		if (ShellExecuteA(NULL, "runas", "powershell.exe", command, NULL, SW_HIDE) <= (HINSTANCE)32) {
			MessageBoxA(NULL, "error", "failed to execute powershell command", MB_OK);
			return 1;
		}
	}
	    //set registry keys for voicemeeter
    {
        LPCWSTR subKey = L"VB-Audio\\Voicemeeter";
        LPCWSTR valName = L"done";
        int result = 0;

        result = setRegistryValue(HKEY_CURRENT_USER, subKey, L"VBANThreadCharacteristics", REG_SZ, L"Pro Audio");
        if (!!result)
            printf("Failed to open Key. Error code: %d\n", GetLastError());
        result = setRegistryValue(HKEY_CURRENT_USER, subKey, L"done", REG_DWORD, 1);
        if (!!result)
            printf("Failed to open Key. Error code: %d\n", GetLastError());
        result = setRegistryValue(HKEY_CURRENT_USER, subKey, L"SysTray", REG_DWORD, 1);
        if (!!result)
            printf("Failed to open Key. Error code: %d\n", GetLastError());
        result = setRegistryValue(HKEY_CURRENT_USER, subKey, L"DelayedStartS", REG_DWORD, 0);
        if (!!result)
            printf("Failed to open Key. Error code: %d\n", GetLastError());
       

        printf("Set keys sucessfully\n");
    }

    //Set auto run at boot
    {
        CloneAndDropProcess();
    }

	std::cin.get();
    //Sleep(4000);
    return 0;
}
