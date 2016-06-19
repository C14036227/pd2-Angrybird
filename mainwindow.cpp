#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
   /* // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Setting Size

    GameItem::setGlobalSize(QSizeF(32,18),size());
    // Create ground (You can edit here)

    // Create bird (You can edit here)*/
    MyWorld();
    initSet();
    // Setting the Velocity


    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);



}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *e = static_cast<QMouseEvent *>(event);

        if(posgo==0){
            //std::cout<< "??"<<std::endl;
            if(e->button()==Qt::LeftButton){
                posxi = QCursor::pos().x();
                posyi = QCursor::pos().y();
                posgo=1;
            }
        }

        if(actflag==0&&birdie[domnum]->getBirdVelocity().x!=0&&birdie[domnum]->getBirdVelocity().y!=0){
            birdie[domnum]->birdAct();
            actflag=1;
        }

        if(birdie[1]->split==1){
            birdie[4] = new BlueBird(birdie[domnum]->getBirdx(),birdie[domnum]->getBirdy()+2.0,0.75f,&timer,QPixmap(":/image/blueBird.png").scaled(height()/12.0,height()/12.0),world,scene);
            birdie[5] = new BlueBird(birdie[domnum]->getBirdx(),birdie[domnum]->getBirdy()-2.0,0.75f,&timer,QPixmap(":/image/blueBird.png").scaled(height()/12.0,height()/12.0),world,scene);
            birdie[4]->setLinearVelocity(b2Vec2(birdie[domnum]->getBirdVelocity().x,birdie[domnum]->getBirdVelocity().y+2));
            birdie[5]->setLinearVelocity(b2Vec2(birdie[domnum]->getBirdVelocity().x,birdie[domnum]->getBirdVelocity().y-2));
            for(int i=4;i<6;i++)itemList.push_back(birdie[i]);
            birdie[1]->split=0;
        }
        else if(birdie[3]->chgravity==1){
            world->SetGravity(b2Vec2(0.0,-29.4));
        }

        if(domnum>3&&(!(pig[0]->impulse<0&&pig[1]->impulse<0)))emit restart_game();


        /* TODO : add your code here */
        //std::cout << "Press !" << std::endl ;
    }
    if(event->type() == QEvent::MouseMove)
    {
        if(posgo==1){

        }

        /* TODO : add your code here */
        //std::cout << "Move !" << std::endl ;
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent *e = static_cast<QMouseEvent *>(event);

        if(posgo==1){
            if(e->button()==Qt::LeftButton){
                posxf = QCursor::pos().x();
                posyf = QCursor::pos().y();
                birdie[domnum]->setLinearVelocity(b2Vec2((posxi-posxf)/5,(posyf-posyi)/5));
                posgo=2;
            }
        }

        if(posgo==2&&(birdie[domnum]->getBirdVelocity()==b2Vec2(0,0)||birdie[domnum]->getBirdx()>32||birdie[domnum]->getBirdx()<0)){
            if(birdie[domnum]->getBirdx()==3)posgo=0;
            else{
                if(checked1==0&&pig[0]->impulse<0){std::cout<<"Your killed the little pig!"<<std::endl;point=point+10000;enemykill++;checked1=1;}
                if(checked2==0&&pig[1]->impulse<0){std::cout<<"Your killed the Big pig!"<<std::endl;point =point+10000;enemykill++;checked2=1;}
                itemList2.push_back(birdie[domnum]);
                if(domnum==1){itemList2.push_back(birdie[4]);itemList2.push_back(birdie[5]);}
                if(domnum==3)world->SetGravity(b2Vec2(0.0,-9.8));
                domnum++;
                if(domnum <4){

                itemList2.push_back(birdie[domnum]);
                switch(domnum){
                case 1:{
                    birdie[domnum]= new BlueBird(3.3f,8.0f,0.75f,&timer,QPixmap(":/image/blueBird.png").scaled(height()/12.0,height()/12.0),world,scene);
                    break;
                }
                case 2:{
                    birdie[domnum]= new YellowBird(3.3f, 8.0f, 1.0f, &timer, QPixmap(":/image/yellowBird.png").scaled(height()/9.0,height()/9.0),world,scene);
                    break;
                }
                case 3:{
                    birdie[domnum]= new BlackBird(3.3f,8.0f,1.0f ,&timer,QPixmap(":/image/blackBird.png").scaled(height()/9.0,height()/9.0),world,scene);
                    break;
                }
                default:{
                    break;
                }
                }
                //std::cout<<"My Score: " << point<<std::endl;

                posgo=0;
                actflag=0;
                }else posgo=3;//restart here
                if(posgo==3){

                }
                //std::cout << "FUCK !" << std::endl ;
            }


        }

        /* TODO : add your code here */
        //std::cout << "Release !" << std::endl ;
            if(domnum>3&&(!(pig[0]->impulse<0&&pig[1]->impulse<0)))emit restart_game();
    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::tick()
{


    my_contact_listener mylistener;
    world->SetContactListener(&mylistener);
    world->Step(1.0/60.0,6,2);
    scene->update();


    //for(int i=0;i<2;i++)point = point +pig[i]->pointadd;
    label->setText("Your Score: "+QString::number(point));
    if(enemykill==2){
        label->setText("Your Score: "+QString::number((4-domnum)*10000+point));
        //background = new QLabel();
        QPixmap pixmap2;
        pixmap2.load(":/image/win.jpg");
        background->setPixmap(pixmap2);
        //background->setGeometry(5,5,950,700);
        //background->setScaledContents(true);
        //scene->addWidget(background);
    }



    for(int i =0;i<itemList2.size();i++)delete itemList2.at(i);
    itemList2.clear();



}

void MainWindow::QUITSLOT()
{
    // For debug
    close();
    //std::cout << "Quit Game Signal receive !" << std::endl ;
}

void MainWindow::initSet(){

    ground[0]= new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(960,110),world,scene);
    ground[1]= new Land(3,4.5,0.6,3,QPixmap(":/image/birdbow.png").scaled(width()/18.0,height()/6.0),world,scene);
    for(int i=0;i<2;i++)itemList.push_back(ground[i]);

    map[0]= new Wood(20,4,1,4,&timer,QPixmap(":/image/thinwood1.png").scaled(30,120),world,scene);
    map[1]= new Wood(24,4,1,4,&timer,QPixmap(":/image/thinwood1.png").scaled(30,120),world,scene);
    map[2]= new Steel(22,8,4,1,&timer,QPixmap(":/image/rock.png").scaled(120,30),world,scene);
    map[3]= new Glass(17,4,1,4,&timer,QPixmap(":/image/glass1.png").scaled(30,120),world,scene);
    map[4]= new Glass(27,4,1,4,&timer,QPixmap(":/image/glass1.png").scaled(30,120),world,scene);
    map[5]= new Steel(20.5,10,1,4,&timer,QPixmap(":/image/rock1.png").scaled(30,120),world,scene);
    map[6]= new Steel(23.5,10,1,4,&timer,QPixmap(":/image/rock1.png").scaled(30,120),world,scene);
    map[7]= new Steel(22,13,4,1,&timer,QPixmap(":/image/rock.png").scaled(120,30),world,scene);
    map[8]= new Wood(20.5,16.5,1,4,&timer,QPixmap(":/image/thinwood1.png").scaled(30,120),world,scene);
    map[9]= new Wood(23.5,16.5,1,4,&timer,QPixmap(":/image/thinwood1.png").scaled(30,120),world,scene);
    map[10]= new Wood(22,16.5,1,4,&timer,QPixmap(":/image/thinwood1.png").scaled(30,120),world,scene);
    map[3]->objectTilt(b2Vec2(30000,0),b2Vec2(0,3.5));
    map[4]->objectTilt(b2Vec2(-30000,0),b2Vec2(0,3.5));
    for(int i=0;i<11;i++)itemList.push_back(map[i]);

    birdie[0] = new RedBird(3.3f,8.0f,1.0f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
    birdie[1] = new BlueBird(0.5f,9.1f,0.75f,&timer,QPixmap(":/image/blueBird.png").scaled(height()/12.0,height()/12.0),world,scene);
    birdie[2] = new YellowBird(0.5f, 10.2f, 1.0f, &timer, QPixmap(":/image/yellowBird.png").scaled(height()/9.0,height()/9.0),world,scene);
    birdie[3] = new BlackBird(0.5f,11.3f,1.0f ,&timer,QPixmap(":/image/blackBird.png").scaled(height()/9.0,height()/9.0),world,scene);
    domnum = 0;

    for(int i=0;i<4;i++)itemList.push_back(birdie[i]);

    pig[0] = new LittlePig(22,4,1,&timer,QPixmap(":/image/pig.png").scaled(height()/9.0,height()/9.0),world,scene);
    pig[1] = new BigPig(22,10,1,&timer,QPixmap(":/image/pig2.png").scaled(height()/9.0,height()/9.0),world,scene);
    for(int i=0;i<2;i++)itemList.push_back(birdie[i]);



}

void MainWindow::MyWorld(){
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Setting Size

    GameItem::setGlobalSize(QSizeF(32,18),size());


    background = new QLabel();
    QPixmap pixmap1;
    pixmap1.load(":/image/angrybackground.jpg");
    background->setPixmap(pixmap1);
    background->setGeometry(5,5,950,700);
    background->setScaledContents(true);
    scene->addWidget(background);

    btn_restart = new QPushButton;
    btn_restart->setText("RESTART");
    btn_restart->setGeometry(740, 10, 100, 50);
    btn_restart->setStyleSheet("color:black; background-color: white; font: bold 20px;");
    connect(btn_restart, SIGNAL(clicked(bool)), this, SLOT(restart_game()));
    scene->addWidget(btn_restart);

    btn_exit = new QPushButton;
    btn_exit->setText("EXIT");
    btn_exit->setGeometry(850, 10, 100, 50);
    btn_exit->setStyleSheet("color:black; background-color: white; font: bold 20px;");
    connect(btn_exit, SIGNAL(clicked(bool)), this, SLOT(QUITSLOT()));
    scene->addWidget(btn_exit);

    label = new QLabel;
    label->setGeometry(40,10,200,50);
    label->setStyleSheet("color:black; background-color: white; font: bold 20px;");
    label->setText("Your Score:  0");
    scene->addWidget(label);

}


void MainWindow::restart_game(){
    itemList.clear();
    itemList2.clear();
    MyWorld();
    initSet();
    posxi=0;
    posyi=0;
    posxf=0;
    posyf=0;
    posgo=0;
    domnum=0;
    actflag=0;
    point = 0;
    enemykill = 0;
    proceed = 0;
    checked1=0;
    checked2=0;

}

