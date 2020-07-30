Action()
{
	lr_start_transaction("06_user_registration");

	lr_start_transaction("open_site");
	
	web_reg_find("Text= A Session ID has been created and loaded into",
		LAST);
	
	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "2&3");
	
	lr_end_transaction("open_site",LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("sign_up_now_click");

	
	web_reg_find("Text=User Information",
		LAST);

	web_url("login.pl", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("sign_up_now_click",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Insert_user_info");

	
	web_reg_find("Text=Welcome to Web Tours",
		LAST);

	web_submit_data("login.pl_2",
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={username}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=passwordConfirm", "Value={password}", ENDITEM, 
		"Name=firstName", "Value= {firstName}", ENDITEM, 
		"Name=lastName", "Value={lastName}", ENDITEM, 
		"Name=address1", "Value={Adress}", ENDITEM, 
		"Name=address2", "Value={ZipCode}", ENDITEM, 
		"Name=register.x", "Value=44", ENDITEM, 
		"Name=register.y", "Value=6", ENDITEM, 
		LAST);

	lr_end_transaction("Insert_user_info",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Continue_click");

	
	web_reg_find("Text= User has returned to the home page.",
		LAST);

	web_url("button_next.gif",
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Continue_click",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Logout");

	
	web_reg_find("Text=Web Tours Navigation Bar",
		LAST);

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Logout",LR_AUTO);

	lr_end_transaction("06_user_registration",LR_AUTO);
}