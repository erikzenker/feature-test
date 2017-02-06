function sleep(delay) {
    var start = new Date().getTime();
    while (new Date().getTime() < start + delay);
}

$(document).ready(function () {
    'use strict';
    paper.install(window);
    paper.setup(document.getElementById('mainCanvas'));


    var c = Shape.Circle(200, 200, 80);
    c.fillColor = 'black';
    var text = new PointText(200, 200);
    text.justification = 'center'
    text.fillColor = 'white'
    text.fontSize = '20'
    text.content = 'hello world'

    var tool = new Tool;
    tool.onMouseDown = function (event) {
        paper.project.activeLayer.removeChildren();
        for(var i = 0; i < 20; i++){
            sleep(10);
            var c = Shape.Circle(event.point, i);
        }
        c.fillColor = 'green';
        paper.view.draw();
    }


});

