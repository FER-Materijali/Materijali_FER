require(["jquery"], function($) {
    $(document).ready(function () {
        var entireCornerPeel = $("#corner-peel"),
        cornerPeelFront = $("#corner-peel img"),
        cornerPeelBehind = $("#corner-peel-behind"),
        bringCornerPeelToFront = function () {
            entireCornerPeel.css({ "z-index": 200 });
        },
        bringCornerPeelToBack = function () {
            entireCornerPeel.css({ "z-index": 50 });
        },
        resizeCornerPeelToDefault = function () {
            cornerPeelFront.stop().animate({
                width: '82px',
                height: '85px'
            }, 220);
            cornerPeelBehind.stop().animate({
                width: '80px',
                height: '80px'
            }, 200, bringCornerPeelToBack); //Note this one retracts a bit faster (to prevent glitching in IE)
        };
        if (location.pathname === "/") {
            setTimeout(function () {
                cornerPeelFront.stop().animate({
                    width: '125px',
                    height: '125px'
                }, 500);

                cornerPeelBehind.stop().animate({
                    width: '122px',
                    height: '120px'
                }, 500, function () {
                    setTimeout(resizeCornerPeelToDefault, 1000);
                });
            }, 1000);
        }

        entireCornerPeel.hover(function () {
            $([cornerPeelFront.get(0), cornerPeelBehind.get(0)]).stop().animate({
                width: '307px',
                height: '318px'
            }, 500);
            bringCornerPeelToFront();
        }, resizeCornerPeelToDefault);
    });
});