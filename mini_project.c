/****************************************************************************************
 *   Name: Ahmed Gamal Abdelrahman Nasr
 *
 *   Describtion : Mini_project.c
 ***************************************************************************************/

# include <stdio.h>

# define Display_size 3 // size of the frist array to the 3 selections
# define sensor_size 4 // size of the second array to the 4 selections

/* defintion of Motor state */
enum motor_state {
	ON = 1 , OFF = 0
};

/* VEHICLE DATA*/
struct vehicle
{
	int Engine ;
	int AC ;
	int vehicle_speed ;
	int Room_temp ;
	int Engine_temp_control ;
	int Engine_temp ;
} vehicle_data ;


char Display_system (char *p1);
char sensor_set_menu(char *index);
void traffic_light_chose(char color);
void Room_temprature (int deg);
void Engine_controller(int temp);
void Print_current_state(void);


/* main function */
int main (void)
{
	char array [Display_size] = { 'a', 'b' , 'c' };
	char sensor[sensor_size] = { 'a', 'b' , 'c' , 'd' };
	char select = Display_system (array); // call function to start system
	char menu ;

	/* Vehicle intial Data  */
	vehicle_data.Engine = ON ;
	vehicle_data.AC = OFF;
	vehicle_data.vehicle_speed = 90 ;
	vehicle_data.Room_temp = 32 ;
	vehicle_data.Engine_temp_control = OFF;
	vehicle_data.Engine_temp = 80 ;

	//user choose to turn on the Engine
	while (select == 'a')
	{
		printf("\n");
		menu = sensor_set_menu(sensor); /* call sensor set menu function */
		if (menu == 'a') // user choose to turn off the engine
		{
			select = Display_system (array); // return to start screen
		}
	}

	/* if the user choose to turn off the Engine */
	while ( select == 'b')
	{
		printf("\n");
		select = Display_system (array);
	}
	return 0 ;
}

/**************************Display function ********************************************/

//  function take an input from user to trun the engine on/off or quit system
char Display_system (char *p1)
{
	char input = ' ';
	printf("a. Trun on the vehicle engine.\n");
	printf("b. Trun off the vehilce engine.\n");
	printf("c. Quit the system\n");
	fflush(stdout);
	scanf(" %c" , &input); // read input
	// user chose : trun on the engine
	if(input == p1[0])
	{
		printf("a. Trun on the vehicle engine.\n");

	}

	// user chose : trun off the engine
	if(input == p1[1])
	{
		printf("b. Trun off the vehilce engine.\n");

	}

	// user chose : quit
	if(input == p1[2])
	{
		printf("Quit the system.\n");
	}

	return input ;
}

/*********************************Sensor menu function*********************************/

/* function that select the sensor set menu */
char sensor_set_menu(char *p2)
{
	char sensor_set ;
	printf("a. Turn off the engine.\n");
	printf("b. set the traffic light color.\n");
	printf("c. set the room temprature.(tempreature sensor)\n");
	printf("d. set the engine temprature.(Engine temprature sensor)\n");
	fflush(stdout);
	//read input from user to select  from the menu
	scanf(" %c" ,&sensor_set);

	/***********************************Select sensor type ********************/

	/* choose traffic light */
	if (sensor_set == p2[1])
	{
		char color ;
		printf("Enter the requierd Color : \n");
		fflush(stdout);
		scanf(" %c" ,&color); // read color
		if ((color =='g')||(color== 'o')||(color== 'r'))
		{
			traffic_light_chose(color); // call traffic light function
		}
	}
	/*chose room temprature */
	if (sensor_set == p2[2])
	{
		int degree ;
		printf("Enter the Room temprature:\n");
		fflush(stdout);
		scanf(" %d" , &degree);//read degree
		Room_temprature (degree); // call room temprature function
	}

	/* Engine Temprature */
	if (sensor_set == p2[3])
	{
		int engine_temp ;
		printf("Enter the Engine temprature:\n");
		fflush(stdout);
		scanf(" %d" , &engine_temp); //read engine temprature
		Engine_controller(engine_temp); // call engine controller function
	}

	return sensor_set ;
}

/*********************************Traffic function**************************************/

/* function that select the traffic light color*/
void traffic_light_chose(char color)
{
	/* if traffic light is green */
	if( color == 'g')
	{
		vehicle_data .vehicle_speed	= 100 ;
	}
	/*traffic light is orange */
	if( color == 'o')
	{
		vehicle_data .vehicle_speed	= 30 ;
	}
	/*trafic light is red*/
	if( color == 'r')
	{
		vehicle_data .vehicle_speed	= 0 ;
	}
	Print_current_state(); // print final state

}

/*********************************Sensor room temptrature function**********************/
void Room_temprature (int deg)
{
	if ((deg < 10 )|| (deg > 30 ))
	{
		vehicle_data.Room_temp = 20 ;
		vehicle_data .AC = ON;
	}
	/* if temprature is greater than 10 and less than 30 trun off the AC */
	else
	{
		vehicle_data .AC = OFF;
	}
	Print_current_state(); // print final state

}

/*********************************Engine temptrature function***************************/
void Engine_controller(int temp)
{
	if ((temp < 100 )|| (temp > 150 ))
	{
		vehicle_data .Engine_temp = 125;
		vehicle_data .Engine_temp_control= ON ;
	}
	/* if temprature is greater than 10 and less than 30 trun off the AC */
	else
	{
		vehicle_data .Engine_temp_control= OFF ;
	}
	Print_current_state(); //print final state

}
/* print function */
void Print_current_state(void)
{

	/********************************* Display the output **********************************/
	/* special case  when vehicle speed is 30 Km/h set the follwing data*/
	if(vehicle_data.vehicle_speed == 30) // it means that the traffic light is orange
	{
		vehicle_data.AC = ON;
		vehicle_data.Room_temp = vehicle_data.Room_temp * (1.25) + 1 ;
		vehicle_data.Engine_temp_control = ON;
		vehicle_data.Engine_temp = vehicle_data.Engine_temp * (1.25) + 1 ;
	}
	if (vehicle_data.Engine == ON)
	{
		printf("Engine state is: ON\n");
	}
	else
	{
		printf("Engine state is : OFF\n");

	}

	if (vehicle_data.AC == ON)
	{
		printf("AC is : ON\n");
	}
	else
	{
		printf("AC is : OFF\n");

	}

	printf("Vehicle Speed:  %d Km/h\n" ,vehicle_data.vehicle_speed);
	printf("Room Temperature:  %d C\n" ,vehicle_data.Room_temp);
	switch (vehicle_data.Engine_temp_control)
	{
	case ON :
		printf("Engine Temperature Controller State: ON\n");
		break ;
	case OFF :
		printf("Engine Temperature Controller State: OFF\n");
		break;
	}

	printf("Engine Temperature:  %d C\n" ,vehicle_data.Engine_temp);


}
