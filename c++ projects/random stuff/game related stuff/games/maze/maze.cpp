
// This is a 1 A maze game 
#include<iostream>
#include<ctime>
#include<cstdlib>/* Used to generate random Numbers to form a random maze */
#include<iomanip>/* Used for output format control to make the maze appearance rules generated */
using namespace std;
/* The function that generates the maze mazegenerator*/
char*mazegenerator(int m,int n)
{
 int i,j,k;/* counter */
 char *p=new char[m*n];/* With length of m*n Array store mxn A maze of size */
 srand(int(time(0)));/* Used to generate random Numbers */
 if(m<10||n<10)// Dense when the order is small 1 Dot, make it interesting 
 for(i=0;i<m*n;i++)
 {
 if(rand()%3==0)p[i]='.';// A random number for 3 Is defined as the path in the maze 
 else p[i]='#';
 }
 else
 for(i=0;i<m*n;i++)
 {
 if(rand()%2==0)p[i]='.';/* When the random number is even, the point in the maze is defined as the path */
 else p[i]='#';
 }
 /* Seal both the left and the top of the boundary except for one 1 Six entrances, only from the right and the bottom, 
  Make the maze more challenging */
 for(i=0;i<m;i++)
 p[i]='#';
 for(i=0;i<m*n;i+=m)
 p[i]='#';
 for(i=m-1;i<m*n;i+=m)
 p[i]='#';
 for(i=m*(n-1);i<m*n;i++)
 p[i]='#';
 /* Let's put the front 3 The order structure of T font */
 p[0]=p[1]=p[2]=p[2*m]=p[2*m+2]='#';
 p[m+1]=p[m+2]=p[2*m+1]='.';
 /* Maze entry is defined as 'x'*/
 p[m]='x';
 /* Mazes are random and need to be constructed 1 pathway */
 /* This is a 1 Each article 3 Turn, 1 The access of the time */
 for(j=3;j<m;j+=3)
 {
 for(k=0;k<3;k++)
 {
 i=(j-3)+k+1;
 if(i*m+j<m*n)
 p[i*m+j]='.';
 }
 }
 for(i=4;i<m;i+=3)
 for(k=0;k<3;k++)
 {
 j=(i-3)+k+2;
 if(i*m+j<m*n)
 p[i*m+j]='.';
 }
 
 return p;
}
/* You need to output a new maze after creating or modifying it */
void showmaze(char*p,int m,int n)
{
 int i,j;/*i On behalf of the line, j On behalf of the column, i*n+j Is the ordinal number of that point in the array */
 for(i=0;i<n;i++)
 {
 for(j=0;j<m;j++)
 cout<<setw(2)<<p[i*m+j];/* Each character takes two to square the maze */
 cout<<endl;
 }
}
/* Maze function mazetraverse*/
void mazetraverse(char*p,int m,int n)
{
 int x,y,z;/*y Is the current position, x Is the former 1 Step, z Is after 1 Step, t Used to enter the command to continue through the maze */
 /* Initialize the x,y, The location of the entrance to the maze */
 x=m;
 y=m+1;
 p[y]='x';/* This is the end of the maze 1 step */
 cout<<" Please press enter to move :";/* Let the user control the maze process */
 cin.get();
 cout<<endl;
 showmaze(p,m,n);/* Output the maze */
 cout<<endl;
 cout<<" Please press enter to move : ";
 cin.get();
 /* The point is to use x,y determine z The value of the */
 while(!((y>m*(n-1))||(((y+1)%m)==0)))/* Perform a loop through the maze before reaching the boundary */
 {
 /* Determine the direction of the right, if the right is '.', The right */
 if(y-x==1)z=y+m;
 if(y-x==m)z=y-1;
 if(y-x==-m)z=y+1;
 if(y-x==-1)z=y-m;
 /* The right not to '.' when y The front of the walk */
 if(p[z]=='#')
 {
 /* judge y The front of theta, if the front is theta '.', The forward */
 if(y-x==1)z=y+1;
 if(y-x==m)z=y+m;
 if(y-x==-m)z=y-m;
 if(y-x==-1)z=y-1;
 /* If the front is '#' Go to the left */
 if(p[z]=='#')
 {
 /* Determine the left position */
 if(y-x==1)z=y-m;
 if(y-x==m)z=y+1;
 if(y-x==-m)z=y-1;
 if(y-x==-1)z=y+m;
 /* If left to '#' To die we need to go backwards */
 if(p[z]=='#')z=x;
 }
 }
 p[z]='x';/* In the end, let it all go z The location of the for 'x', Represents the trace of a journey */
 showmaze(p,m,n);
 cout<<endl;
 cout<<" Please press enter to move : ";
 cin.get();
 cout<<endl;
 /* replace x,y Move the current position */
 x=y;
 y=z;
 }
}
int main()
{
 int m,n;/*n Is the order of the maze. Due to the limit of output window size, 
 n It cannot be more than the number of characters per line */
 cout<<"  Chen Weihang's maze game \n My maze is very neat! ^_^\n"<<endl;
 cout<<" This is a 1 A maze of arbitrary size ,"<<endl;
 cout<<" Each maze is different. \n"<<endl;
 cout<<" Because of the screen 1 Second most display 80 A character, \n Here, each character takes up two more Spaces, "<<endl
 <<" So the input exceeds 40 The steps are not pretty, \n It's still true. Ha ha \n"<<endl;
 cout<<" Please enter the width of the maze in turn m And highly n(m>2,n>2):"<<endl;
 /* You can test multiple sets of data */
 while(cin>>m>>n)
 {
 char*a=mazegenerator(m,n);
 showmaze(a,m,n);
 cout<<endl;
 cout<<" Long March 1 Step: \n"<<endl;
 mazetraverse(a,m,n);
 cout<<" Congratulations to you! You've made it through the maze! "<<endl<<endl;
 cout<<" To try a new maze, enter the order of the new maze n(n>2) . \n Otherwise, press the ctrl+z And then according to the enter The end of the "<<endl;
 }
}
