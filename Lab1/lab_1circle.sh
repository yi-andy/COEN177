# Name: Andy Yi 
# Date: 1/10/20 (the day you have lab) 
# Title: Lab1 – Circle Area 
# Description: This program computes the area of a circle.

response="Yes"
while [ $response != "No" ]
do
        echo "Enter radius of circle: "
        read radius
        area=`echo "$radius^2*3.14159" | bc`
        echo "The area of the area is $area"

        echo "Would you like to repeat for another circle [Yes/No]?"
        read response

done
