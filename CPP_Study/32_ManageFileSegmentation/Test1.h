#pragma once // 헤더가 중복해서 추가되더라도 방지해준다. -- 헤더 가드
// 이거는 공식 c++은 아님, visual studio에서만!

// #pragma의 다른 방식 ! =>공식적인 방식
#ifndef _TEST1_H__
#define _TEST1_H__

// 대부분의 프로젝트에서는 소스파일안에 header, cpp를 같이 넣는다.

void Test_1();

void Test_2();// 선언부

void Test_3();

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

#endif