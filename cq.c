void insert() //Inserting an element in to the queue
{
        int item;
        if(front==(rear+1)%max_size)
        {
                printf("\nQueue Overflow:");
        }
        else
        {
                printf("Enter the element to be inserted:\t");
                scanf("%d",&item);
                rear=(rear+1)%max_size;
                cqueue[rear]=item;

                if(front==-1)
                {
                        front=0;
                        rear=0;
                }

        }

}//end of insert()

void del()      //deleting an element from the queue
{
        int item;
        if(front==-1)
        {
                printf("\nQueue Underflow:");
        }
        else
        {
                item=cqueue[front];
                printf("\nThe deleted element: %d\t",item);
                if(front==rear)
                {
                        front=-1;
                        rear=-1;
                }
                else
                {
                        front=(front+1)%max_size;
                }

        }
}//end of del()

void display()  //To display the queue elements
{
        int i;
        if(front==-1)
        {
                printf("\nQueue is Empty:");
        }
        else
        {
                printf("\nThe queue elements are:\n" );
                if(front<rear)
                {
                        for(i=front;i<=rear;i++)
                        {
                                printf("%d\t",cqueue[i]);
                        }
                }
                else
                {
                        for(i=0;i<=rear;i++)
                        {
                                printf("%d\t",cqueue[i]);
                        }
                        for(i=front;i<max_size;i++)
                        {
                                printf("%d\t",cqueue[i]);
                        }
                }

        }

}//end of display()
