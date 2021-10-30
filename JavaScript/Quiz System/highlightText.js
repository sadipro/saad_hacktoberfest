const highlightText = document.querySelectorAll('.ask input');
highlightText.forEach(option => {
    var ok = option.addEventListener('click', e => {
        console.log(e.toElement.nextElementSibling.style.color = 'white');
    });
});