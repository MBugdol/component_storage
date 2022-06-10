#ifndef MENUHANDLER
#define MENUHANDLER

enum class Status {
	offline,
	mainMenu,
	addComponent,
	takeComponent,
	manufacturers,
	exporting
};

class MenuHandler
{
public:
	void start();
	void stop();

	void launchMain();
	void launchAdd();
	void launchTake();
	void launchManufacturers();
	void launchExport();

	void setStatus(Status);
private:
	Status current_status;
};

#endif