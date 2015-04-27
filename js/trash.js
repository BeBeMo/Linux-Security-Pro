var sys = require('sys');
var exec = require('child_process').exec;


function trash(){

	var text = document.getElementById("text");
	var but = document.getElementById('button').value;

	if(but == "查看垃圾"){
		var expr1 = "bash ./shell/clean/1.sh";
		var expr2 = "bash ./shell/clean/2.sh";
		var expr3 = "bash ./shell/clean/3.sh";
		var expr4 = "bash ./shell/clean/4.sh";
		var t1;
		var t2;
		var t3;
		var t4;
		b1 = document.getElementById("button");
		b1.innerHTML="清理垃圾";
		b1.value = "清理垃圾";
		i1 = document.getElementById("ima");
		i1.src = "./images/fullbin.png";
		text.innerHTML="<br><img src='./images/t1.png' width='20px' height='20px' align='center'/>回收站(bytes)<br><textarea id='res1' cols='10' style='background-color:#F0F9FD;border:solid 0px gray;'></textarea><br><img src='./images/t2.png' width='20px' height='20px' align='center'/>包临时文件(bytes)<br><textarea id='res2' cols='10' style='background-color:#F0F9FD;border:solid 0px gray;'></textarea><br><img src='./images/t3.png' width='20px' height='20px' align='center'/>缩略图(bytes)<br><textarea id='res3' cols='10' style='background-color:#F0F9FD;border:solid 0px gray;'></textarea><br><img src='./images/t4.png' width='20px' height='20px' align='center'/>最近使用文档记录(bytes)<br><textarea id='res4' cols='10' style='background-color:#F0F9FD;border:solid 0px gray;'></textarea><br><canvas id='myCanvas' width='380' height='200'></canvas>"
			exec(expr1,function(error,stdout,stderr){
				a=document.getElementById("res1");
				a.innerHTML=stdout;
				t1=parseInt(stdout);


				exec(expr2,function(error,stdout,stderr){
					a=document.getElementById("res2");
					a.innerHTML=stdout;
					t2=parseInt(stdout);


					exec(expr3,function(error,stdout,stderr){
						a=document.getElementById("res3");
						a.innerHTML=stdout;
						t3=parseInt(stdout);


						exec(expr4,function(error,stdout,stderr){
							a=document.getElementById("res4");
							a.innerHTML=stdout;
							t4=parseInt(stdout);

							//绘制饼图，获取饼图数据
							var pie = new RGraph.Pie('myCanvas',[t1,t2,t3,t4]);
							//绘制饼图标题
							pie.Set('chart.title','系统垃圾分布图');
							//绘制饼图标签文字
							pie.Set('chart.labels',['回收站', '包临时文件', '缩略图', '最近使用文档记录']);
							//指定饼图分隔线宽
							pie.Set('chart.linewidth',5);
							//指定饼图分隔线颜色
							pie.Set('chart.strokestyle','white');
							//指定工具条提示信息的出现效果为淡入效果
							pie.Set('chart.tooltips.effect','fade');
							//指定当鼠标指针在饼块上移动时出现工具条提示信息
							pie.Set('chart.tooltips.event','onmousemove');
							//指定工具条提示信息的文字
							pie.Set('chart.tooltips',['回收站', '包临时文件', '缩略图', '最近使用文档记录']);
							//指定工具条提示信息具有3d效果
							pie.Set('chart.highlight.style','3d');  
							//绘制饼图
							pie.Draw();
						});
					});
				});
			});
	}

	else{
		var expr1 = "bash ./shell/clean/5.sh";
		var expr2 = "bash ./shell/clean/6.sh";
		var expr3 = "bash ./shell/clean/7.sh";
		var expr4 = "bash ./shell/clean/8.sh";
		var expr5 = "bash ./shell/clean/9.sh";
		b2 = document.getElementById("button");
		b2.innerHTML = "查看垃圾";
		b2.value = "查看垃圾";
		i2 = document.getElementById("ima");
		i2.src = "./images/emptybin.png";
		exec(expr1,function(error,stdout,stderr){
			a=document.getElementById("res1");
			a.innerHTML=stdout;
		});
		exec(expr2,function(error,stdout,stderr){
			a=document.getElementById("res2");
			a.innerHTML=stdout;
		});
		exec(expr3,function(error,stdout,stderr){
			a=document.getElementById("res3");
			a.innerHTML=stdout;
		});
		exec(expr4,function(error,stdout,stderr){
			a=document.getElementById("res4");
			a.innerHTML=stdout;
		});
		exec(expr5,function(error,stdout,stderr){
			a=document.getElementById("res5");
			a.innerHTML=stdout;
		});
		text.innerHTML="<br><img src='./images/t5.png' width='20px' height='20px' align='center'/>清理回收站(bytes)<br><textarea id='res1' cols='10' style='background-color:#F0F9FD;border:solid 0px gray;'></textarea><br><img src='./images/t6.png' width='20px' height='20px' align='center'/>清理包临时文件(bytes)<br><textarea id='res2' cols='10' style='background-color:#F0F9FD;border:solid 0px gray;'></textarea><br><img src='./images/t7.png' width='20px' height='20px' align='center'/>清理缩略图(bytes)<br><textarea id='res3' cols='10' style='background-color:#F0F9FD;border:solid 0px gray;'></textarea><br><img src='./images/t8.png' width='20px' height='20px' align='center'/>清理最近使用文档记录(bytes)<br><textarea id='res4' cols='10' style='background-color:#F0F9FD;border:solid 0px gray;'></textarea><br><img src='./images/t9.png' width='20px' height='20px' align='center'/>清理总量(bytes)<br><textarea id='res5' cols='10' style='background-color:#F0F9FD;border:solid 0px gray;'></textarea>"
		
	}
};
