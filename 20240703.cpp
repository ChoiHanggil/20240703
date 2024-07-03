#include <iostream>
enum class Color
{
	White = 0,
	Black = 1
};

class MyClass
{
public:
	//기본 생성자
	MyClass(){ std::cout << "기본" << std::endl; }
	//복사 생성자
	MyClass(const MyClass& from){ std::cout << "복사" << std::endl; }
	//복사 대입 연산자
	MyClass& operator = (const MyClass& from){ std::cout << "복사 대입 연산자" << std::endl; return *this;}

	//이동 생성자
	MyClass(MyClass&& from) { std::cout << "이동" << std::endl;}
	//&& <- 우측값 참조
	//이동 대입 연산자
	MyClass& operator = (const MyClass&& from)  { std::cout << "이동 대입 연산자" << std::endl; return *this;}
};

// 스마트 포인터 (Smart Pointer)
// std::unique_ptr			리소스 : 포인터 1:1 포인터 삭제하면 리소스도 무조건 없어짐
// std::shared_ptr			리소스 : 포인터 1:N 리소스 한개에 여러개 포인터 가능. 마지막 포인터가 없어져야 리소스가 사라짐
// std::weak_ptr			소유하지 않음	

class MyClassSP
{
public:
	int value;

	MyClassSP() { std::cout << "생성" << std::endl; }
	~MyClassSP() { std::cout << "소멸" << std::endl; }
};
int main()
{
	//람다식
	/*
	[capture] (paraneters) -> return(Type)
	{

	}
	*/
	//매개 변수를 2개를 받는 함수
	[](int a, int b) -> int { return 0; };
	//컴파일러가 아는 경우 반환값 int 생략가능
	auto f = []()->int { return 0; };

	// capture [] [=] [&]  =: 복사 , &: 참조
	
	int x = 1;
	auto lambda = [=]() {std::cout << x << std::endl; };

	//-----------------------------------------------------
	MyClass c1 (std::move(MyClass()));


	Color c2;
	c2 = Color::White;

	std::unique_ptr<MyClassSP> p(std::make_unique<MyClassSP>());
	p->value = 1;
	MyClassSP* pp = p.get(); //get 포인터를 가져옴;

	p.release(); //소멸 delete대체

	p.reset(); // p = nullptr
}
