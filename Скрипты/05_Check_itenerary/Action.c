Action()
{
	lr_start_transaction("05_Check_itenerary");

	lr_start_transaction("open_site");
	
	web_reg_save_param_ex(
		"ParamName=userSession",
		"LB/IC=userSession\" value=\"",
		"RB/IC=\"/>",
		"Ordinal=1",
		LAST);

	web_reg_find("Text=A Session ID has been created and loaded into",
		LAST);
	
	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("open_site",LR_AUTO);
	
	web_set_sockets_option("SSL_VERSION", "2&3");
	
	lr_think_time(5);

	lr_start_transaction("Login");

	web_reg_find("Text=User password was correct",
		LAST);
	
	web_reg_find("Text=Welcome, <b>{username}</b>",
		LAST);
	
	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t4.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={username}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=login.x", "Value=32", ENDITEM,
		"Name=login.y", "Value=3", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("Login",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Itenerary_click");

	web_reg_find("Text= User wants the intineraries.",
		LAST);

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Itenerary_click",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Logout");

	web_reg_find("Text= A Session ID has been created and loaded into",
		LAST);

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Logout",LR_AUTO);

	lr_end_transaction("05_Check_itenerary",LR_AUTO);
}