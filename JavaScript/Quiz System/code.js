const correctAnswers = ['A', 'B', 'D', 'B'];
const form = document.querySelector('.quiz-form');
const answerDiscription = document.querySelectorAll('.ask');
const result = document.querySelector('.result');
const popup = document.querySelector('.pop-up');
const error = document.querySelector('.error');
const articleQuiz = document.querySelector('article');


// Window is the global object of the JS
// Therfore we donthave to explecitily write the window. in every statement
//  window.console.log()
//  console.log() 
//  are the same

// Used to select all childs of the FORM
// Child of the form == Individual MCQs
const formChildren = Array.from(form.children);;
var array = formChildren.filter(child => {
    if (child.className === 'my-5 ask') {
        return true;
    }
});

form.addEventListener('submit', e => {
    let i = [5, 5, 5, 5];
    let counter = 0;
    e.preventDefault();
    let score = 0;
    const userAnswers = [form.q1.value, form.q2.value, form.q3.value, form.q4.value];
    userAnswers.forEach((answer, index) => {
        if (answer === 'A' || answer === 'B' || answer === 'C' || answer === 'D') {
            if (answer === correctAnswers[index]) {
                score += 25;
            }
        } else {
            counter++;
        }
    });


    if (counter > 0) {
        articleQuiz.style.display = 'none';
        popup.classList.remove('d-none');
        error.addEventListener('click', e => {
            articleQuiz.style.display = 'block';
            popup.classList.add('d-none');
        });
        popup.addEventListener('click', e => {
            articleQuiz.style.display = 'block';
            popup.classList.add('d-none');
        })
    } else {

        let j = 0;
        let objects;
        userAnswers.forEach((answer, index) => {
            if (answer === correctAnswers[index]);
            else {
                array[index].innerHTML += `<p style="color:black;">You answer was incorrect.<br>The correct answer is option ${correctAnswers[index]}</p>`;
                // const paragraph = document.querySelectorAll('.gg');
                // console.log(array[index].contains(paragraph[i]));
                // objects = array[index].contains(paragraph[i]);
                // i++;
                i[j] = index;
                j++;
            }
        });
        // console.log(i);
        window.scrollTo(0, 0);
        result.classList.remove('d-none');

        // to animate the score 
        let output = 0;
        const timer = window.setInterval(() => {
            result.querySelector('span').textContent = `${output}%`;
            if (output === score) {
                clearInterval(timer);
            } else {
                output++;
            }
        }, 15)
    }

    // Function to remove the newly added <p> tag that displays the error
    let j = 0;
    form.addEventListener('submit', e => {
        e.preventDefault();
        for (let x = 0; x < i.length; x++) {
            if (i[x] === 5) {
                j++;
            } else {
                let news = i[j];
                answerDiscription[i[j]].lastChild.remove();
                j++;
            }
        }
    })
});