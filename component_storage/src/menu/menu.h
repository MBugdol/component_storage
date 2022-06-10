#pragma once
#include <vector>
#include <string>

class Menu
{
public:
	void display();
	int getChoice();
	void setTitle(std::string);
	void setContent(std::vector<std::string>);
protected:
	std::string title;
	std::vector<std::string> content;
};

