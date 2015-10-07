// var firstObject ={
// }

// var taskArray = ["element1", "element2", 2, 3, firstObject];
// console.log(taskArray);

var taskArray = [];

var displayTasks = function(){
	var taskListContainer = document.getElementById('taskList');
	taskListContainer.innerHTML = '';

	for(var i = 0; i<taskArray.length; i++){
		console.log('task ' + i + ":" + taskArray[i]);

		var newTask = document.createElement('div');

		newTask.id = i;
		newTask.className = 'task';

		//paragraph inside our div
		var task = document.createElement('p');

		//insert our existing task-text into the paragraph
		task.innerHTML = taskArray[i];

		//create a delete button
		var deleteButton = document.createElement('button');
		deleteButton.id = "deleteButton";
		//have text on delete button
		deleteButton.innerHTML = "delete";

		deleteButton.addEventListener("click", function(e){
			e.preventDefault();
			deleteTask(e);

		})

		newTask.appendChild(task);
		newTask.appendChild(deleteButton);
		taskListContainer.appendChild(newTask);
	}
}

var saveTask = function(){
	var taskInput = document.getElementById('newTask');
	var newTask = taskInput.value;

	//push this into our array

	taskArray.push(newTask);

	//clear the input field
	taskInput.value = "";

	//update the list
	displayTasks();

	//show us our array
	console.log(taskArray);


}

var deleteTask = function(e){
	//get the parent elements (the task lines) id
	var taskNumber = e.target.parentElement.id;
	//delete the task from the array
	taskArray.splice(taskNumber, 1);

	//update task list
	displayTasks();
}

var init = function(){
	console.log("window loaded");

	var addButton = document.getElementById('addButton');

	addButton.addEventListener('click', function(e){
		e.preventDefault();
		saveTask();
	})

}

window.onload = init();