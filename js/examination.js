var sys = require('sys');
var exec = require('child_process').exec;


function examination(){

	var text = document.getElementById("text");
	var but = document.getElementById('button').value;
	var expr1 = "bash ./shell/time/time.sh";
	var expr2 = "bash ./shell/cpu/cpu.sh";
	var expr3 = "bash ./shell/netspeed/speed.sh";
	if(but == "一键体检"){
		var str = "体检体检......";
		var expr4 = "bash ./shell/free/meca.sh";
		var expr5 = "bash ./shell/ufw/ufw.sh";
		var expr6 = "bash ./shell/zomble/zomble_count.sh";
		b1 = document.getElementById("button");
		b1.innerHTML="一键修复";
		b1.value = "一键修复";
		i1 = document.getElementById("ima");
		i1.src = "./images/e2.jpg";
	}

	else{
		var str = "修复修复......"
		var expr4 = "bash ./shell/free/clean_cache.sh";
		var expr5 = "bash ./shell/ufw/open_ufw.sh";
		var expr6 = "bash ./shell/zomble/zomble_kill.sh";
		b2 = document.getElementById("button");
		b2.innerHTML = "一键体检";
		b2.value = "一键体检";
		i2 = document.getElementById("ima");
		i2.src = "./images/e3.png";
	}
	//  text.innerHTML="<textarea id='n' rows='28' cols='20' style='background-color:#F0F9FD;border:solid 0px gray;'>"+str+"</textarea>";
	text.innerHTML=
		"<br><img src='./images/time.png' width='20px' height='20px' align='center'/>   电脑运行时间<br><textarea id='res1' style='background-color:#F0F9FD;border:solid 0px gray;'></textarea><br><img src='./images/cpu.png' width='20px' height='20px' align='center'/>   cpu使用情况<br><textarea id='res2' style='background-color:#F0F9FD;border:solid 0px gray;'></textarea><br><img src='./images/speed.png' width='20px' height='20px' align='center'/>   网速测试<br><textarea id='res3' style='background-color:#F0F9FD;border:solid 0px gray;'></textarea><br><img src='./images/cache.png' width='20px' height='20px' align='center'/>   内存/缓存使用情况<br><textarea id='res4' style='background-color:#F0F9FD;border:solid 0px gray;'></textarea><br><img src='./images/ufw.png' width='20px' height='20px' align='center'/>   防火墙状态<br><textarea id='res5' style='background-color:#F0F9FD;border:solid 0px gray;'></textarea><br><img src='./images/zomble.png' width='20px' height='20px' align='center'/>   僵尸进程<br><textarea id='res6' style='background-color:#F0F9FD;border:solid 0px gray;'>";   
	exec(expr1,function(error,stdout,stderr){
		a=document.getElementById("res1");
		a.innerHTML=stdout;
	});
	exec(expr2,function(error,stdout,stderr){
		b=document.getElementById("res2");
		b.innerHTML=stdout;
	});
	exec(expr3,function(error,stdout,stderr){
		b=document.getElementById("res3");
		b.innerHTML=stdout;
	});
	exec(expr4,function(error,stdout,stderr){
		b=document.getElementById("res4");
		b.innerHTML=stdout;
	});
	exec(expr5,function(error,stdout,stderr){
		b=document.getElementById("res5");
		b.innerHTML=stdout;
	});

	exec(expr6,function(error,stdout,stderr){
		b=document.getElementById("res6");
		b.innerHTML=stdout;
	});
};

