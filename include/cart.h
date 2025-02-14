/*!
 * Copyright (C) 2022 Carry Assistant Trolley (C.A.T) Technologies
 *  
 * Jia Wei Tan, February 16, 2022.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111, USA.
 */

/// \brief General Purpose Input Output for Raspberry Pi

#ifndef CART_H
#define CART_H

#include <iostream>

class Cart
{

public:

    Cart()
    {
    	void start();
    }
    
    ~Cart()
    {
    	void stop();
    }
    
    /// \brief Left forward wheel declaration
    void lw_Forward();

    /// \brief Right forward wheel declaration
    void rw_Forward();

    /// \brief Left backward wheel declaration
    void lw_Backward();

    /// \brief Right forward wheel declaration
    void rw_Backward();

    /// \brief write motor declaration
    void writeMotor(int L, int R);

    /// \brief compute angle  declaration
    void compute_angle(int a, int b, int c);
    
    /// \brief left IR sensor declaration
    int get_leftIR();

    /// \brief right IR sensor declaration
    int get_rightIR();

    /// \brief get calcualted angle declaration
    float getAngle();

    /// \brief get calculated distance declaration
    float getDistance_a();
    
    /// \brief calculate angle declaration
    float estimateRobotAngle(float angle_old_robot, int rotation_left, int rotation_right, float timeStep);
    
    /// \brief angle-time estimation declaration
    float angleToTime(float angle_diff, int rotation_left, int rotation_right);

private:
    static const int left_IR = 4;
    static const int right_IR = 15;
    static const int motorL = 13;
    static const int motorR = 12;
    static const int en1 = 5;
    static const int en2 = 6;
    static const int en3 = 23;
    static const int en4 = 24;
    static const int offset_a = 62;
    static const int offset_b = 62;
    static const int offset_c = 62;
    float d_a;
    float d_b;
    float d_c;
    float rocAngle = 0.685557;
    float timeStep_s;
    float angle_new_robot;
};

#endif
