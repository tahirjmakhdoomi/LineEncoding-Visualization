#include<iostream>
#include<string>
#include<graphics.h>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<vector>
#define hx 600
#define wx 1000
using namespace std;
int palindrome(string sub) //returns length if the string is palindrome otherwize 'zero'
{
	int i,j;
	for(i = 0, j = sub.length()-1 ; i <= j; i++,j--)
	{
		if(sub.at(i) != sub.at(j))
		{
			return 0;
		}
		
	}
	return sub.length();
	
}
int printmenu(){	//prints the choices menu and returns the case for switch
	int c1;
	cout << "Enter Your Choice: \n";
	cout << "1 -> Unipolar\n";
	cout << "2 -> Polar\n";
	cout << "3 -> AMI\n";
	cin >> c1;
	return c1;
}

int main()
{
	srand(time(NULL)); //for seeding the rand function to produce different random no's on every program start
	string data; // used to store data stream
	cout << "Hello! User. How many data bits you want me to generate?\n";
	int bits;
	cin >> bits;
	if(!(bits>0)){
		cout << "Not a valid statment\n";
		getch();
		exit(0);
	}
	cout << "What do you want me to generate?\n";
	cout << "1 -> Completely Random Stream\n";
	cout << "2 -> Random Stream with some fixed sequence\n";
	int c0;
	cin >> c0;
	if(c0 == 1)
	{	
		//complete random generator
		for(int k = 0 ; k< bits;k++)
		{
			
			if(rand()%2){
				data.append("1");
			}
			else{
				data.append("0");
			}
		}
	
//		for(int i = 0; data[i] != '\0' ; i++)
//		{ 												// 	verifying whether the input steam 
//			if(!(data[i] == '0' || data[i] == '1'))		//	entered is valid bit stream
//			{
//				cout << "Invalid Data Stream\n";
//				exit(0);
//			}
//		}
		
	}
	else if(c0 == 2)
	{
		//generator with fixed no of sequence can be modified to include others
		int scmb;
		cout << "1 -> 8 consecutive 0's \n";
		cout << "2 -> 4 consecutive 0's \n";
		cin >> scmb;
		srand(time(NULL)); //for seeding rand fn and to calculae index where fixed sequence can be inserted
		int w;				// particularly for making the things completely random ;)
		if(scmb == 1)
		{	
			//8 'zeros' fixed sequence random no generator
			if(bits>8)
			{	
				
				for(w = 0 ; w< bits - 8;w++)
				{		
					if(rand()%2)
					{
						data.append("1");
					}
					else
					{
						data.append("0");
					}
				}
				data.insert(rand()%w,"00000000");
				
			}
			else{
				cout << "The bitstream is invalid to get this sequence\n";
				getch();
				exit(0);
			}
			
		}
		else if(scmb == 2)
		{	//4 'zeros' fixed sequence random no generator
			if(bits>4)
			{
				for(w = 0 ; w< bits - 4;w++)
				{		
					if(rand()%2)
					{
						data.append("1");
					}
					else
					{
						data.append("0");
					}
				}
				data.insert(rand()%w,"0000");
				
			}
			else{
				cout << "The bitstream is invalid to get this sequence\n";
				getch();
				exit(0);
			}
			
			
		}
		else
		{
			cout << "Invalid Input :/ Try Again \n";
			getch();
			exit(0);
			
				
		}
		
		
	}
	else
	{
		cout << "Invalid Input";
		getch();
		exit(0);
		
	}
	
	cout << endl << "The Generated Sequence : -> " << data << endl;  
	
	//longest common palindrome subsequence
	int x =0,longest = 0,index ;
	vector<int> number;
	while(data[x] != '\0')
	{
		int y = x ;
		while(data[y] != '\0')
		{
			int k = palindrome(data.substr(x,y-x + 1)); 
			//cout << " " << s.substr(x,y-x + 1) << " " << k << '\n' ;
			if(k > 0 && k > longest)
			{
				number.erase(number.begin(),number.end());
				longest  = k;
				number.push_back(x);
				
				
			}
			else if(k > 0 && k == longest)
			{
				number.push_back(x);
				
				
			}
			
			y++;
		}
		
		x++;
	}
	cout << '\n' << "Longest Palindromic Sequence -> \n";
	cout <<"Length : "<<  longest << "\n";
	for (int it=0; it < number.size() ;it++)
	{
		cout << "Starting Index: " << number[it] << "\nSequence :"<< data.substr(number[it],longest) << '\n'<< '\n' ;	
	}
	
	int g,stepsize,it=0,sx,sy; 
	switch(printmenu())
	{
		case 1:
			//unipolar
			g = initwindow(wx,hx,"Welcome"); //initializing windows
			setlinestyle(SOLID_FILL,16,4); 
			line(8,0,8,getmaxy()); //drawing y axis
			line(0,getmaxy()/2,getmaxx(),getmaxy()/2); 	//drawing x axis
			stepsize = (getmaxx() - 8)/(data.length()+2); // chossing adaptable stepsize so that change in the no of bits doesn't make it turn faulty
			sx = 8; 		//starting index to start graph from
			sy = getmaxy()/2;//starting coordinate from where y can be calculated(which actually should be at the middle)
			while(data[it] != '\0')
			{
				//outtextxy(sx,sy,"|");
				setlinestyle(DASHED_LINE,3,1);
				line(sx+stepsize,10,sx+stepsize,getmaxy()-10);
				setlinestyle(SOLID_FILL,16,4);	
				if(data[it] == '0')
				{
					sx = sx + stepsize;
				
				}
				else
				{
					if(data[it-1] != '1')
					line(sx,sy,sx,sy-stepsize);
					line(sx,sy-stepsize,sx+stepsize,sy-stepsize);
					if(data[it+1] == '1'){
						
					}
					else
					{
						line(sx+stepsize,sy-stepsize,sx+stepsize,sy);
					}
					 
					sx = sx+stepsize;
				}
				it++;
				
			}
			//outtextxy(sx,sy,"|");
			getch();
			closegraph(g);
			exit(0);
			
		case 2:
			//polar
			cout<<"1 -> Polar NRZ-L\n";
			cout<<"2 -> Polar NRZ-I\n";
			cout<<"3 -> Biphase\n";
			int c2;
			cin >> c2;
			switch(c2)
			{
				case 1:
						//polar -> nrz-l
						g = initwindow(wx,hx,"Welcome");
						setlinestyle(SOLID_FILL,16,4);
						line(8,0,8,getmaxy());
						line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
						stepsize = (getmaxx() - 8)/(data.length()+2);
						sx = 8;
						sy = getmaxy()/2;
						while(data[it] != '\0')
						{
							//	outtextxy(sx,sy,"|");
							setlinestyle(DASHED_LINE,3,1);
							line(sx+stepsize,10,sx+stepsize,getmaxy()-10); //forming grid
							setlinestyle(SOLID_FILL,16,4);
							if(data[it] == '0')
							{
								if(sx != 8 && data[it-1] != '0')
								line(sx,sy,sx,sy+stepsize);
								line(sx,sy+stepsize,sx+stepsize,sy+stepsize);
								if(data[it+1] != '0')
								line(sx+stepsize,sy+stepsize,sx+stepsize,sy);
								
							}
							else
							{
								if(sx != 8 && data[it-1] != '1')
								line(sx,sy,sx,sy-stepsize);
								line(sx,sy-stepsize,sx+stepsize,sy-stepsize);
								if(data[it+1] != '1')
								line(sx+stepsize,sy-stepsize,sx+stepsize,sy);
													 
								
							}
							sx = sx+stepsize;
							it++;
						}
						//outtextxy(sx,sy,"|");
						getch();
						closegraph(g);
					
						exit(0);
				case 2:
					//polar -> nrz-i
						g = initwindow(wx,hx,"Welcome");
						setlinestyle(SOLID_FILL,16,4);
						line(8,0,8,getmaxy());
						line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
						stepsize = (getmaxx() - 8)/(data.length()+2);
						sx = 8;
						sy = getmaxy()/2;
						while(data[it] != '\0')
						{
							//outtextxy(sx,sy,"|");
							setlinestyle(DASHED_LINE,3,1);
							line(sx+stepsize,10,sx+stepsize,getmaxy()-10);
							setlinestyle(SOLID_FILL,16,4);
							if(data[it] == '0')
							{	
								if(sx == 8)
								{
									line(sx,sy+stepsize,sx+stepsize,sy+stepsize);
									sy=sy+stepsize;
								}
								else
								{	
									line(sx,sy,sx+stepsize,sy);
								}
							}
							else
							{
								if(sx == 8){
									line(sx,sy-stepsize,sx+stepsize,sy-stepsize);
									sy = sy-stepsize;
									
								}
								else 
								{
								if(sy > getmaxy()/2)
								{
									line(sx,sy,sx,sy-2*stepsize);
									sy = sy - 2*stepsize;
										
								}
								else
								{	
									line(sx,sy,sx,sy+2*stepsize);
									sy = sy + 2*stepsize;
								}
								line(sx,sy,sx+stepsize,sy);
								}
							}
							sx = sx+stepsize;
							it++;
						}
						//outtextxy(sx,sy,"|");
						getch();
						closegraph(g);
						exit(0);
				case 3:
					cout << "1 -> Manchester\n";
					cout << "2 -> Differential Manchester\n";
					int c5;
					cin >> c5;
					switch(c5)
					{
						case 1:
							//biphase -> manchester
							g = initwindow(wx,hx,"Welcome");
							setlinestyle(SOLID_FILL,16,4);
							line(8,0,8,getmaxy());
							line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
							stepsize = (getmaxx() - 8)/(data.length()+2);
							sx = 8;
							sy = getmaxy()/2;
							while(data[it] != '\0')
							{
								//outtextxy(sx,sy,"|");
								setlinestyle(DASHED_LINE,3,1);
								line(sx+stepsize,10,sx+stepsize,getmaxy()-10);
								setlinestyle(SOLID_FILL,16,4);
								if(data[it] == '0')
								{
									//if(data[it-1] != '0')
									//line(sx,sy,sx,sy+stepsize);
									//line(sx,sy+stepsize,sx+stepsize,sy+stepsize);
									//if(data[it+1] != '0')
									//line(sx+stepsize,sy+stepsize,sx+stepsize,sy);
								
									line(sx,sy-stepsize,sx+(stepsize/2),sy-stepsize);
									line(sx+(stepsize/2),sy-stepsize,sx+(stepsize/2),sy+stepsize);
									line(sx+(stepsize/2),sy+stepsize,sx+stepsize,sy+stepsize);
									if(data[it+1] == '0')
									line(sx+stepsize,sy+stepsize,sx+stepsize,sy-stepsize);
								}
								else
								{
									//if(data[it-1] != '1')
									//line(sx,sy,sx,sy-stepsize);
									//line(sx,sy-stepsize,sx+stepsize,sy-stepsize);
									//if(data[it+1] != '1')
									//line(sx+stepsize,sy-stepsize,sx+stepsize,sy);
									
									line(sx,sy+stepsize,sx+(stepsize/2),sy+stepsize);
									line(sx+(stepsize/2),sy+stepsize,sx+(stepsize/2),sy-stepsize);
									line(sx+(stepsize/2),sy-stepsize,sx+stepsize,sy-stepsize);
									if(data[it+1] == '1')	
									line(sx+stepsize,sy-stepsize,sx+stepsize,sy+stepsize);				 
									
								}
								sx = sx+stepsize;
								it++;
							}
							//outtextxy(sx,sy,"|");
							getch();
							closegraph(g);	
							exit(0);
						case 2:
								g = initwindow(wx,hx,"Welcome");
								setlinestyle(SOLID_FILL,16,4);
								line(8,0,8,getmaxy());
								line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
								stepsize = (getmaxx() - 8)/(data.length()+2);
								sx = 8;
								sy = getmaxy()/2;
								while(data[it] != '\0')
									{
										//outtextxy(sx,sy,"|");
										setlinestyle(DASHED_LINE,3,1);
										line(sx+stepsize,10,sx+stepsize,getmaxy()-10);
										setlinestyle(SOLID_FILL,16,4);
										if(data[it] == '0')
										{	
											if(sx == 8)
											{
												line(sx,sy+stepsize,sx+(stepsize/2),sy+stepsize);
												line(sx+(stepsize/2),sy+stepsize,sx+(stepsize/2),sy-stepsize);
												line(sx+(stepsize/2),sy-stepsize,sx+stepsize,sy-stepsize);
												sy=sy-stepsize;
											}
											else
											{	
												if(sy > getmaxy()/2)
												{
													line(sx,sy,sx,sy-2*stepsize);
													line(sx,sy-(2*stepsize),sx+(stepsize/2),sy-(2*stepsize));
													line(sx+(stepsize/2),sy-(2*stepsize),sx+(stepsize/2),sy);
													line(sx+(stepsize/2),sy,sx+stepsize,sy);
										
												}
												else
												{	
													line(sx,sy,sx,sy+2*stepsize);
													line(sx,sy+(2*stepsize),sx+(stepsize/2),sy+(2*stepsize));
													line(sx+(stepsize/2),sy+(2*stepsize),sx+(stepsize/2),sy);
													line(sx+(stepsize/2),sy,sx+stepsize,sy);
													
												}
												
											
											}
										}
										else
										{
											if(sx == 8)
											{
												line(sx,sy-stepsize,sx+(stepsize/2),sy-stepsize);
												line(sx+(stepsize/2),sy-stepsize,sx+(stepsize/2),sy+stepsize);
												line(sx+(stepsize/2),sy+stepsize,sx+stepsize,sy+stepsize);
												sy=sy+stepsize;	
																				
											}
											else 
											{
												if(sy > getmaxy()/2)
												{
													line(sx,sy,sx+(stepsize/2),sy);
													line(sx+(stepsize/2),sy,sx+(stepsize/2),sy-(2*stepsize));
													sy = sy - 2*stepsize;
										
												}
												else
												{	
													line(sx,sy,sx+(stepsize/2),sy);
													line(sx+(stepsize/2),sy,sx+(stepsize/2),sy+(2*stepsize));
													sy = sy + 2*stepsize;
												}
													line(sx+(stepsize/2),sy,sx+stepsize,sy);
											}
										}
									sx = sx+stepsize;
									it++;
								}
								//outtextxy(sx,sy,"|");
								getch();
								closegraph(g);
								exit(0);
						default:
							cout << "Invalid Option\n";
							getch();
							exit(0);
						
					}
					break;
				default:
					cout << "Invalid Option\n";
					
					getch();
					exit(0);
			}
			break;
		case 3:
			cout<< "1 -> AMI\n";
			cout<< "2 -> Pseudo Ternary\n";
			int c4;
			cin >> c4;
			switch(c4)
			{
				case 1:
					cout << "1 -> AMI Without Scrambling\n";
					cout << "2 -> AMI with Scrambling\n";
					int xc;
					cin >> xc;
					switch(xc){
						case 1:
							//AMI
							scmb:
							g = initwindow(wx,hx,"Welcome");
							setlinestyle(SOLID_FILL,16,4);
							line(8,0,8,getmaxy());
							line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
							stepsize = (getmaxx() - 8)/(data.length()+1);
							sx = 8;
							sy = (getmaxy()/2)-stepsize;
							while(data[it] != '\0')
							{
								//outtextxy(sx,getmaxy()/2,"|");
								setlinestyle(DASHED_LINE,3,1);
								line(sx+stepsize,10,sx+stepsize,getmaxy()-10);
								setlinestyle(SOLID_FILL,16,4);
								if(data[it] == '1' || data[it] == 'B')
								{	//sy can be programmed for scrambling
									if(sy<getmaxy()/2)
									{	
										//upper
										line(sx,sy+stepsize,sx,sy);
										line(sx,sy,sx+stepsize,sy);
										line(sx+stepsize,sy,sx+stepsize,sy+stepsize);
										sy = sy + (2*stepsize);
										 
									}
									else
									{	
									//lower
										line(sx,sy-stepsize,sx,sy);
										line(sx,sy,sx+stepsize,sy);
										line(sx+stepsize,sy,sx+stepsize,sy-stepsize);
										sy = sy - (2*stepsize);
										
									}
									
								}
								else if(data[it] == 'V')
								{	//sy can be programmed for scrambling
									if(sy>getmaxy()/2)
									{//upper
										line(sx,sy-(2*stepsize),sx,sy-stepsize);
										line(sx,sy-(2*stepsize),sx+stepsize,sy-(2*stepsize));
										line(sx+stepsize,sy-(2*stepsize),sx+stepsize,sy-stepsize);
										
									}
									else
									{	
									//lower
										
										line(sx,sy+(2*stepsize),sx,sy+stepsize);
										line(sx,sy+(2*stepsize),sx+stepsize,sy+(2*stepsize));
										line(sx+stepsize,sy+(2*stepsize),sx+stepsize,sy+stepsize);
										
									}
									
								}
							sx = sx+stepsize;
							it++;
							}
							//outtextxy(sx,getmaxy()/2,"|");
							getch();
							closegraph(g);
							exit(0);
							
						case 2:
							int so;
							cout << "Enter Type Of Scrambling\n";
							cout << "1 -> HDB3\n";
							cout << "2 -> B8ZS\n";
							cin >> so;
							switch(so)
							{
								case 1:
									{
									
									int k = data.find("0000");

									while( k >= 0 && k < data.length())
									{
										int x = k,count = 0;
										while(x >= 0){
											if(data[x] == 'V') break;
											if(data[x] == '1') count++;
											x--;
										} 				
										if(count%2 == 0)
										{
											data.replace(k,4,"B00V");	
										}
										else
										{
											data.replace(k,4,"000V");
										}
										
										k = data.find("0000");
									}
										goto scmb;
										break;
								}
								case 2:
										{
										int k = data.find("00000000");

										while( k >= 0 && k < data.length())
										{				
											data.replace(k,8,"000VB0VB");
											k = data.find("00000000");
										}
										goto scmb;
										break;
										}
								default:
										cout << "Invalid Option\n";
										getch();
										exit(0);
								
							}
							
						
						default:
							cout << "Invalid Imput\n";
							
							getch();
							exit(0);
					}
					
					
					
				case 2:
					g = initwindow(wx,hx,"Welcome");
						setlinestyle(SOLID_FILL,16,4);
						line(8,0,8,getmaxy());
						line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
						stepsize = (getmaxx() - 8)/(data.length()+1);
						sx = 8;
						sy = (getmaxy()/2)+stepsize;
						while(data[it] != '\0')
						{
							//outtextxy(sx,getmaxy()/2,"|");
							setlinestyle(DASHED_LINE,3,1);
							line(sx+stepsize,10,sx+stepsize,getmaxy()-10);
							setlinestyle(SOLID_FILL,16,4);
							if(data[it] == '0')
							{	//sy can be programmed for scrambling
								if(sy<getmaxy()/2)
								{//upper
									line(sx,sy+stepsize,sx,sy);
									line(sx,sy,sx+stepsize,sy);
									line(sx+stepsize,sy,sx+stepsize,sy+stepsize);
									sy = sy + (2*stepsize);
									 
								}
								else
								{	
								//lower
									line(sx,sy-stepsize,sx,sy);
									line(sx,sy,sx+stepsize,sy);
									line(sx+stepsize,sy,sx+stepsize,sy-stepsize);
									sy = sy - (2*stepsize);
									
								}
								
							}
							sx = sx+stepsize;
							it++;
						}
						//outtextxy(sx,getmaxy()/2,"|");
						getch();
						closegraph(g);
					
						exit(0);
					
				
				default:
					cout << "Invalid Option";
					getch();
					exit(0);	
			}
			break;

		default:
			cout << "Invalid Option\n";
			break;
	}
	getch();
	
}
