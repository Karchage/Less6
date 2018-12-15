#include <iostream>
typedef void (*WriteFunc)(int,char);
void PaintC(int size,char simbol)
{
	
	int c=size-1;
	for(int i=0;size>i;i++)
	{
		for(int j=0;size>j;j++)
		{
			if(i==j)
			{
				std::cout<<simbol;
			}
			else if(j==c)
			{
				if(c!=size/2)
				{
					std::cout<<simbol;
				}
			}
			else std::cout<<" ";
		}
		c=c-1;
		std::cout<<"\n";
	}
}
void PaintHD(int size,char simbol)
{
	
for (int i=0; i<size/2; i++)
    {
        for (int j=0; j<size; j++)
        {
        	if (j>=size/2-i && j<=size/2+i)
        	{
            	if (j>size/2-i && j<size/2+i)
            	{
                	std::cout<<" ";
            	}	
            	else std::cout<<simbol;
       		}
            else std::cout<<" ";
        }
        std::cout<<"\n";
    }
    for (int i=size/2; i>=0; i--)
    {
        for (int j=0; j<size; j++)
        {
            if (j>=size/2-i && j<=size/2+i)
            {
                if(j>size/2-i && j<size/2+i)
				{
					std::cout<<" ";
				}
				else std::cout<<simbol;
            }
            else std::cout<<" ";
        }
        std::cout<<"\n";
    }
}
void PaintFD(int size,char simbol)
{
	
    for (int i=0; i<size/2; i++)
    {
        for (int j=0; j<size; j++)
        {
            if (j>=size/2-i && j<=size/2+i)
            {
                std::cout<<simbol;
            }
            else std::cout<<" ";
        }
        std::cout<<"\n";
    }
    for (int i=size/2; i>=0; i--)
    {
        for (int j=0; j<size; j++)
        {
            if (j>=size/2-i && j<=size/2+i)
            {
                std::cout<<simbol;
            }
            else std::cout<<" ";
        }
        std::cout<<"\n";
    }
}
int main() 
{
	int size,figure;
	char simbol;
	WriteFunc PaintFunc[3];
	PaintFunc[1] = PaintC;
	PaintFunc[2] = PaintHD;
	PaintFunc[3] = PaintFD;
	std::cout<<"Please select figure\n1) Cross\n"<<"2) Hollow Diamond\n"<<"3) Filled Diamond\n";
	std::cin>>figure;
	std::cout<<"Please select size: ";
	std::cin>>size;
	std::cout<<"Please select simbol: ";
	std::cin>>simbol;
	std::cout<<"\nThis is your figure\n\n";
	PaintFunc[figure](size,simbol);
	return 0;
}


