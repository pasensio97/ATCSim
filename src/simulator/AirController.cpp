/*
 * AirController.cpp
 *
 *  Created on: 21/07/2014
 *      Author: paco
 *
 *  Copyright 2014 Francisco Martín
 *
 *  This file is part of ATCSim.
 *
 *  ATCSim is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  ATCSim is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with ATCSim.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "AirController.h"
#include "Airport.h"
#include "Flight.h"
#include "Position.h"
#include <list>
#include <fstream>

namespace atcsim{

AirController::AirController() {
	// TODO Auto-generated constructor stub

}

AirController::~AirController() {
	// TODO Auto-generated destructor stub
}

void
TCAS(Flight *f)
{
  Position pos0(3500.0, 0.0, 100.0);

  float distance_safety = COLLISION_DISTANCE*2;
  float critical_distance = COLLISION_DISTANCE*1.5;

  std::list<Flight*> flights = Airport::getInstance()->getFlights();
  std::list<Flight*>::iterator it;
  for(it = flights.begin(); it!=flights.end(); ++it){
    if(f != (*it) ){
      float distance = f->getPosition().distance((*it)->getPosition());
			float distance_to_airport1 = f->getPosition().distance(pos0);
			float distance_to_airport2 = (*it)->getPosition().distance(pos0);

      if (distance < distance_safety){

          if(distance < critical_distance){
            float pitch = asin(15*M_PI/180);
            if( !f->getIsSiding() ){
              if (distance_to_airport1 > distance_to_airport2){
                f->setInclination( f->getInclination() + pitch); //goes up
                (*it)->setInclination( (*it)->getInclination() - pitch); // goes down
                if (f->getIsSiding() == false){
                  f->setIsSiding(true);
                  f->setIsLanding(false);
                  f->setIsNewLanding(true);
                  f->setIsApproached(false);
                }

            }else if (distance_to_airport1 < distance_to_airport2){
              (*it)->setInclination( (*it)->getInclination() + pitch ); //goes up
              f->setInclination( f->getInclination() - pitch ); // goes down
              if ((*it)->getIsSiding() == false){
                (*it)->setIsSiding(true);
                (*it)->setIsLanding(false);
                (*it)->setIsNewLanding(true);
                (*it)->setIsApproached(false);
              }
            }
          }
        }

std::cerr << "AQUIIIIIIIIIIIIIIIII" << '\n';

    	}
    }
  }
}

void
siding(Flight *f)
{
  float distanceA0, distanceB0;

  Position actual_position;

  Position posA0(-3500.0,-2000.0, 5000);
  Position posB0(-3500.0, 2000.0, 5000);

  Position posA1(-7500.0,-5250.0, 5000);
  Position posB1(-7500.0, 5250.0, 5000);

  Position posA2(-10000.0,-8500.0, 5000);
  Position posB2(-10000.0, 8500.0, 5000);

  Position posA3(-7500.0,-5250.0, 5000);
  Position posB3(-7500.0, 5250.0, 5000);

  Position posA4(-3500.0,-15000.0, 5000);
  Position posB4(-3500.0, 15000.0, 5000);

  Route rA0, rA1, rA2, rA3, rA4;
  Route rB0, rB1, rB2, rB3, rB4;

  rA0.pos = posA0;
  rA0.speed = 250;
  rB0.pos = posB0;
  rB0.speed = 250;
  rA1.pos = posA1;
  rA1.speed = 250;
  rB1.pos = posB1;
  rB1.speed = 250;
  rA2.pos = posA2;
  rA2.speed = 250;
  rB2.pos = posB2;
  rB2.speed = 250;
  rA3.pos = posA3;
  rA3.speed = 250;
  rB3.pos = posB3;
  rB3.speed = 250;
  rA4.pos = posA4;
  rA4.speed = 250;
  rB4.pos = posB4;
  rB4.speed = 250;

  actual_position = f->getPosition();

  distanceA0 = actual_position.distance(posA0);
  distanceB0 = actual_position.distance(posB0);

  if(f->getRoute()->empty()){
    if(actual_position.distance(posA0) < actual_position.distance(posB0)){
      f->getRoute()->push_front(rA0);
      f->getRoute()->push_back(rA1);
      f->getRoute()->push_back(rA2);
      f->getRoute()->push_back(rA3);
      f->getRoute()->push_back(rA4);
      f->setIsNewSidind(false);
    }else{
      f->getRoute()->push_front(rB0);
      f->getRoute()->push_back(rB1);
      f->getRoute()->push_back(rB2);
      f->getRoute()->push_back(rB3);
      f->getRoute()->push_back(rB4);
      f->setIsNewSidind(false);
    }
  }

  if(actual_position.distance(posA4) < 50 ||  actual_position.distance(posB4) < 50){
    f->setIsSiding(false);
    f->setIsApproached(true);
  }
  std::cerr << "SIDIIIIING" << '\n';
}

void
assign_approach(Flight *f)
{

  float distance0, distance1, distance2, distance3,
        distance4, distance5, distance6, distance7,
        distance0246, distance1357;

  Position actual_position;

  Position pos0(0.0,-15000.0, 3000);
  Position pos1(0.0, 15000.0, 3000);

  Position pos2(5000.0,-11250.0, 3000);
  Position pos3(5000.0, 11250.0, 3000);

  Position pos4(10000.0,-7500.0, 3000);
  Position pos5(10000.0, 7500.0, 3000);

  Position pos6(15000.0,-3750.0, 3000);
  Position pos7(25000.0, 3750.0, 3000);

  Position pos02(5000,-8000, 2000);
  Position pos13(5000, 8000, 2000);
  Position pos46(9000,-3500, 2000);
  Position pos57(9000, 3500, 2000);

  Position pos0246(5000,-1500, 1000);
  Position pos1357(5000, 1500, 1000);

  Route r0, r1, r2, r3, r4, r5, r6, r7,
        r02, r13, r46, r57,
        r0246, r1357;

  r0.pos = pos0;
  r0.speed = 200;
  r1.pos = pos1;
  r1.speed = 200;
  r2.pos = pos2;
  r2.speed = 200;
  r3.pos = pos3;
  r3.speed = 200;
  r4.pos = pos4;
  r4.speed = 200;
  r5.pos = pos5;
  r5.speed = 200;
  r6.pos = pos6;
  r6.speed = 200;
  r7.pos = pos7;
  r7.speed = 200;
  r02.pos = pos02;
  r02.speed = 150;
  r13.pos = pos13;
  r13.speed = 150;
  r46.pos = pos46;
  r46.speed = 150;
  r57.pos = pos57;
  r57.speed = 150;
  r0246.pos = pos0246;
  r0246.speed = 125;
  r1357.pos = pos1357;
  r1357.speed = 125;

  actual_position = f->getPosition();

  distance0 = actual_position.distance(pos0);
  distance1 = actual_position.distance(pos1);
  distance2 = actual_position.distance(pos2);
  distance3 = actual_position.distance(pos3);
  distance4 = actual_position.distance(pos4);
  distance5 = actual_position.distance(pos5);
  distance6 = actual_position.distance(pos6);
  distance7 = actual_position.distance(pos7);

  distance0246 = actual_position.distance(pos0246);
  distance1357 = actual_position.distance(pos1357);

  std::list<float>compare_distances;
  std::list<float>::iterator it;

  compare_distances.push_back(distance0);
  compare_distances.push_back(distance1);
  compare_distances.push_back(distance2);
  compare_distances.push_back(distance3);
  compare_distances.push_back(distance4);
  compare_distances.push_back(distance5);
  compare_distances.push_back(distance6);
  compare_distances.push_back(distance7);

  compare_distances.sort();
  it = compare_distances.begin();

  if(!f->getIsApproached()){
    f->getRoute()->clear();
    if(distance0 == (*it) ){
      f->getRoute()->push_front(r0);
      f->getRoute()->push_back(r02);
      f->getRoute()->push_back(r0246);
    }else if(distance1 == (*it) ){
      f->getRoute()->push_front(r1);
      f->getRoute()->push_back(r13);
      f->getRoute()->push_back(r1357);
    }else if(distance2 == (*it) ){
      f->getRoute()->push_front(r2);
      f->getRoute()->push_back(r02);
      f->getRoute()->push_back(r0246);
    }else if(distance3 == (*it) ){
      f->getRoute()->push_front(r3);
      f->getRoute()->push_back(r13);
      f->getRoute()->push_back(r1357);
    }else if(distance4 == (*it) ){
      f->getRoute()->push_front(r4);
      f->getRoute()->push_back(r46);
      f->getRoute()->push_back(r0246);
    }else if(distance5 == (*it) ){
      f->getRoute()->push_front(r5);
      f->getRoute()->push_back(r57);
      f->getRoute()->push_back(r1357);
    }else if(distance6 == (*it) ){
      f->getRoute()->push_front(r6);
      f->getRoute()->push_back(r46);
      f->getRoute()->push_back(r0246);
    }else if(distance7 == (*it) ){
      f->getRoute()->push_front(r7);
      f->getRoute()->push_back(r57);
      f->getRoute()->push_back(r1357);
    }
    f->setIsApproached(true);
  }

  if(distance0246 < 50 ||  distance1357 < 50){
      if(!f->getIsLanding())
        f->setIsApproached(false);
        f->setIsLanding(true);
  }

}

void
AirController::landing(Flight *f)
{

  Position pos0(3500.0, 0.0, 100.0);
  Position pos1(1500.0, 0.0, 50.0);
  Position pos2(200.0, 0.0, 25.0);
  Position pos3(-750.0, 0.0, 25.0);

  Route r0, r1, r2, r3;

  r0.pos = pos0;
  r0.speed = 150.0;
  r1.pos = pos1;
  r1.speed = 100.0;
  r2.pos = pos2;
  r2.speed = 70.0;
  r3.pos = pos3;
  r3.speed = 10.0;

  if(f->getRoute()->empty())
  {
    f->getRoute()->push_back(r3);
    f->getRoute()->push_front(r2);
    f->getRoute()->push_front(r1);
    f->getRoute()->push_front(r0);
    f->setIsNewLanding(false);
    std::cerr << "SE ASIGNA LAND" << '\n';
	}
}

void
AirController::doWork()
{
  std::list<Flight*> flights = Airport::getInstance()->getFlights();
  std::list<Flight*>::iterator it;

  for(it = flights.begin(); it!=flights.end(); ++it)
  {
    /*//TCAS(*it);
    if( (*it)->getIsSiding() && (*it)->getIsNewSidind() ){
      (*it)->getRoute()->clear();
      siding(*it);
      std::cerr << "ENTRA SIDING" << '\n';
    }else if( (*it)->getIsLanding() && (*it)->getIsNewLanding() ){
      (*it)->getRoute()->clear();
      landing(*it);
      std::cerr << "ENTRA LANDING" << '\n';
    }else{
      assign_approach(*it);
    }*/
    assign_approach(*it);
    if( (*it)->getIsLanding() && (*it)->getIsNewLanding() ){
      (*it)->getRoute()->clear();
      landing(*it);
      std::cerr << "ENTRA LANDING" << '\n';
    }
	}

}

}  // namespace atcsim
