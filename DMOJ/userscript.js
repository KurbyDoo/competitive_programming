function calcDateDif(startDateStr) {
    let difMin = ~~((Date.now() - Date.parse(startDateStr))/60000);
    let difH = ~~(difMin/60);
    difMin %= 60;
    let difStr = ' (';
    if(difH === 0) difStr += difMin === 1 ? '1 minute' : difMin + ' minutes';
    else {
        difStr += difH === 1 ? '1 hour' : difH + ' hours';
        if(difMin !== 0) difStr += ' ' + (difMin === 1 ? '1 minute' : difMin + ' minutes');
    }
    return difStr += ')';
}

$(document).ready(function(){
    $('td.user-name').map((i, td) => {
        const startTNode = td.querySelector(".start-time");
        if(startTNode && startTNode.innerText !== 'Participation ended.'){
            $(td).css('background-color', '#FFFFBF');
            const startDateStr = startTNode.children[0].getAttribute('data-iso');
            td.querySelector(".rating > a").innerText += calcDateDif(startDateStr);
        }
    });
});