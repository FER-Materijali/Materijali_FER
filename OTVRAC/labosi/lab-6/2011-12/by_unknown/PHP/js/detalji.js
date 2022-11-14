$(document).ready(function()
{
	$("tr[title]").tooltip({
		open: function() {
			var tooltip = $(this).tooltip("widget");
			$(document).mousemove(function(event) {
				tooltip.position({
					my: "left center",
					at: "right center",
					offset: "25 25",
					of: event
				});
			})
			// trigger once to override element-relative positioning
			.mousemove();
		},
		close: function() {
			$(document).unbind("mousemove");
		}
	});
});

function showMoreInfo(oib)
{
	var req;
	if (window.XMLHttpRequest)
	{
		req = new XMLHttpRequest();
	}
	else if (window.ActiveXObject)   // Internet Explorer 
	{
		req = new ActiveXObject("Microsoft.XMLHTTP");
	}
	
	if (req)
	{
		var url = "http://localhost:81/PHP/detalji.php?oib=" + oib;
		req.open("GET", url, true);
		req.send(null);
		
		var element = document.getElementById("detailInfo");
		element.innerHTML = '<img src="ajax-loader.gif" alt="Tra&#x017E;im..." />';
		element.style.position = "fixed";
		element.style.bottom = "30px";
		element.style.left = "0px";
		element.style.width = "210px";
		element.style.color = "#ccc"; 
		element.style.textShadow = "0px 3px 8px #2a2a2a";
		element.style.borderLeft = "4px solid #fece2f";
		element.style.paddingLeft = "25px";
		element.style.font = "12px \"Trebuchet MS\", \"Lucida Grande\"";
		element.style.lineHeight = "180%";
	  
		req.onreadystatechange = function()
			{
				if (req.readyState == 4)
				{
					if (req.status == 200)
					{
						element.innerHTML = req.responseText;
					}
					else
					{
						element.innerHTML = "Error";
					}
				}
			};
	}
}