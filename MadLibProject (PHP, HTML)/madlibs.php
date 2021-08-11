<?php
    // get the data from the form
    $noun1 = $_POST['noun1'];
    $adjective1 = $_POST['adjective1'];
    $verb1 = $_POST['verb1'];
    $noun2 = $_POST['noun2'];     
    $adjective2 = $_POST['adjective2'];
    $verb2 = $_POST['verb2'];
    $noun3 = $_POST['noun3'];     
    $adjective3 = $_POST['adjective3'];
    $verb3 = $_POST['verb3'];     
    
    // escape the unformatted input
    $noun1_escaped = htmlspecialchars($noun1);
    $adjective1_escaped = htmlspecialchars($adjective1);
    $verb1_escaped = htmlspecialchars($verb1);
    $noun2_escaped = htmlspecialchars($noun2);
    $adjective2_escaped = htmlspecialchars($adjective2);
    $verb2_escaped = htmlspecialchars($verb2);
    $noun3_escaped = htmlspecialchars($noun3);
    $adjective3_escaped = htmlspecialchars($adjective3);
    $verb3_escaped = htmlspecialchars($verb3);

    $madlib1 = "It was a " . $adjective1_escaped . " and rainy day, at High Point University.
Some students inside the school of " . $noun1_escaped . " were talking about
a way to " . $verb1_escaped . " without using a " . $noun2_escaped . " All of a sudden,
Dr. " . $adjective2_escaped . " bursted through the door, saying they need to leave,
'there's a massive " . $noun3_escaped . " outside!' The students jumped out of their
seats and began " . $verb2_escaped . "ing towards the exit. Once they got outside, they
couldn't believe their eyes. It was a " . $adjective3_escaped .  " and large rubber duck!
The students " . $verb3_escaped . "ed away as fast as they could. After hours of battle,
Nido slayed the mighty beast with his magic fountain powers!";
    $madlib2 = "In a land full of dragons and stuff, there was a powerful hero named " . $noun1_escaped  .  ". He was granted a powerful weapon that is very " . $adjective1_escaped . " to fight the beasts. After fighting for many years, a tyrant who made his name by " . $noun2_escaped . " appeared and had a very " . $adjective2_escaped . " look. Its plan is to fill the land with lots of very evil " . $noun3_escaped  . " The hero wouldn’t let this happen and " .  $verb1_escaped . " to challenge the villain to a fight of " . $verb2_escaped . ". The hero fought very " . $adjective2_escaped . " and won. Good thing the Hero wasn’t challenged to " . $verb2_escaped . " otherwise he would have lost.";
    	$madlib3 = "Their once was a man who wanted to own a " . $noun1_escaped . " machine. Lets call him Ted. Unfortunetly he had no idea how to even run a functioning " . $noun1_escaped . " machine. So like any other " . $adjective1_escaped . " person Ted decided to go on the internet to find out. Ted found out that the average machine cost could vary from a " . $adjective2_escaped . " low amount to a very massive amount of money. For just $200 Ted could " . $verb1_escaped . " a machine for a steal of a price. However, even after buying one, it is also important to purchase the needed ". $noun2_escaped . " incase the machine breaks and needs to be fixed. While a cheaper model may be easier to obtain, they will also require a lot more repairs or possible quick fixes. In addition to just owning one, its also important to put a lot of " . $noun3_escaped . " for people to purchase while they " . $verb2_escaped . " around whatever shopping center the machine may end up in. Speaking of shopping centers it will be important to make an agreement with whoever may own the property the machine will be on. Typically it is not unheard of to get a " . $adjective3_escaped . " lawyer to quickly put together a contract in order for both parties to " . $verb3_escaped . ". And that's generally what goes into owning a " . $noun1_escaped . " machine, atleast that what the article on vending machines says..";
?>
<!DOCTYPE html>
<html>
<style type = "text/css">
#images img{
margin-bottom: 50px;
margin-right: 50px;
}
#headerbar{
margin:0;
background-color: black;
}
#contentwrapper {
background-image: url("./images/trivbg.png");
background-position: center center;
position: fixed;
width: 100%;
height: 100%;
margin-bottom: 0;
}
#text {
margin-top: 17%;
margin-right: 30%;
margin-left: 30%;
background-color: white;
border-style: inset;
}
#createanother a{
color:blue;
background-color: white;
border-color: black;
padding:5px;
text-decoration: none;
border-style: outset;
margin-top: 15px;
}
#createanother a:hover{
border-style: inset;
}
</style>
<head>
    <title>Generated MadLib</title>
    <link rel="stylesheet" type="text/css" href="stylesheet.css">
</head>
<body>
    <main><div id="menu">
        <h1>Your Selected MadLib</h1><br>
<div id = "header"><h2>MadLib<br><font color="blue">Mania</h2></div>
</div>
<div id = "headerbar">
<br>
</div>
<div id="contentwrapper">
<div id ="text">
<p><center>
<?php 
if($_COOKIE['madlib'] == 1) {
echo $madlib1;
}
if($_COOKIE['madlib'] == 2) {
echo $madlib2;
}
if($_COOKIE['madlib'] == 3) {
echo $madlib3;
}
?>
<br><br>
<div id="createanother" style="color:white;text-decoration:none;">
<a href="./index.html">Click Here To Create Another</a>
</div>
</center></p></div>
</div>
<br>

    </main>
</body>
</html>
