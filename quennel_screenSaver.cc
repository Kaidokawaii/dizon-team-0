 #include "particle.h"
  2 #include <iostream>
  3 #include <string>
  4 using namespace std;
  5 
  6 
  7 Movement::Movement(string new_type) {
  8     type = new_type;
  9 }
 10 
 11 Particle::Particle() : x(0), y(0), velocityX(0), velocityY(0), frames(0), movementType("STREAMER"), R(255), G(255), B(255) {}
 12 
 13 Particle::Particle(double x, double y) : x(x), y(y), velocityX(0), velocityY(0), frames(0), movementType("STREAMER"), R(255), G(255), B(255) {}
 14 
 15 Particle::Particle(double x, double y, double vx, double vy, double life, Movement m) : x(x), y(y), velocityX(vx), velocityY(vy), frames(life), movementType(m), R(255), G(255), B(255) {}
 16 
 17 
 18 void Particle::set_x(double new_x) {
 19         x = new_x;
 20 }
 21 void Particle::set_y(double new_y) {
 22         y = new_y;
 23 }
 24 void Particle::set_velocityX(double vx) {
 25         velocityX = vx;
 26 }
 27 void Particle::set_velocityY(double vy) {
 28         velocityY = vy;
 29 }
 30 void Particle::set_frames(double life) {
 31         frames = life;
 32 }
 33 void Particle::set_movementType(Movement m) {
 34         movementType = m;
 35 }
 36 double Particle::get_x() const { return x; }
 37 
 38 double Particle::get_y() const { return y; }
 39 
 40 double Particle::get_velocityX() const { return velocityX; }
 41 
 42 double Particle::get_velocityY() const { return velocityY; }
 43 
 44 double Particle::get_frames() const { return frames; }
 45 
 46 string Particle::get_movementType() const { return movementType.type;}
 47 
 48 void Particle::physics(ParticleSystem *owner = nullptr) {
 49         x += velocityX;
 50         y += velocityY;
 51         if (movementType.type == "BALLISTIC") {
 52             velocityY += 0.5;
 53         }
 54         /*
 55         if (movementType.type == "FIREWORK") {
 56             if (frames == 0) {
 57                 Particle *p1 = new Particle(x,y,-1*velocityX,velocityY,2.0,Movement("STREAMER"));   
 58                 Particle *p2 = new Particle(x,y,velocityX,-1*velocityY,2.0,Movement("STREAMER"));   
 59                 Particle *p3 = new Particle(x,y,-1*velocityX,-1*velocityY,2.0,Movement("STREAMER"));    
 60                 Particle *p4 = new Particle(x,y,velocityX,velocityY,2.0,Movement("STREAMER"));  
 61                 if (owner) {
 62                     owner->add(p1);
 63                     owner->add(p2);
 64                     owner->add(p3);
 65                     owner->add(p4);
 66                 }
 67             }
 68         }
 69         */
 70         if (movementType.type == "FIREWORK" && frames <= 1) {
 71             Particle* p1 = new Particle(x, y, -1, 1, 20, Movement("STREAMER"));
 72             p1->setColor(R,G,B);
 73             Particle* p2 = new Particle(x, y, 1, -1, 20, Movement("STREAMER"));
 74             p2->setColor(R,G,B);
 75             Particle* p3 = new Particle(x, y, -1, -1, 20, Movement("STREAMER"));
 76             p3->setColor(R,G,B);
 77             Particle* p4 = new Particle(x, y, 1, 1, 20, Movement("STREAMER"));
 78             p4->setColor(R,G,B);
 79 
 80             if (owner) {
 81                 owner->add(p1);
 82                 owner->add(p2);
 83                 owner->add(p3);
 84                 owner->add(p4);
 85             }
 86         }
 87         frames--;
 88 }
 89 
 90 void Particle::setColor(int r, int g, int b) {
 91     R = r; G = g; B = b;
 92 }
 93 
 94 int Particle::getR() const {
 95     return R;
 96 }
 97 
 98 int Particle::getG() const {
 99     return G;
100 }
101 
102 int Particle::getB() const {
103     return B;
104 }
105 
~                                                                                                                                                                                                                                                                                                                                                    
~                                                                                                                                                                                                                                                                                                                                                    
~                                                                                      
