var camera, scene, renderer;
var circle1, material1, mesh1, circle2, material2, mesh2, nose, material3, mesh3;

init();
animate();

$(document).on('mousemove', function(e){
    $("#lips").css({
       left:  e.pageX,
       top:   e.pageY
    });
});

function init(){

    camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 1, 10000);
    camera.position.z = 700;

    scene = new THREE.Scene();
    circle1 = new THREE.CircleGeometry(200, 200, 200);

    material1 = new THREE.MeshBasicMaterial({
        color: 0xFF9900,
        wireframe: true
    });

    mesh1 = new THREE.Mesh(circle1, material1);
    scene.add(mesh1);

    circle2 = new THREE.CircleGeometry(200, 200, 200);

    material2 = new THREE.MeshBasicMaterial({
        color: 0x3399FF,
        wireframe: true
    });

    mesh2 = new THREE.Mesh(circle2, material2);

    scene.add(mesh2);


    nose = new THREE.CylinderGeometry(100, 200, 300, 50);

    material3 = new THREE.MeshBasicMaterial({
        color: 0x66CC33,
        wireframe: true
    });

    mesh3 = new THREE.Mesh(nose, material3);

    scene.add(mesh3);


    renderer = new THREE.WebGLRenderer();
    renderer.setSize(window.innerWidth, window.innerHeight);

    document.body.appendChild(renderer.domElement);

}

function animate() {

    requestAnimationFrame(animate);

    mesh1.rotation.x += 0.02;
    mesh1.rotation.y += 0;

    mesh1.position.set(300, 350, 0)


    mesh2.rotation.x -= 0.02;
    mesh2.rotation.y += 0;

    mesh2.position.set(-300, 350, 0)


    mesh3.rotation.x += 0;
    mesh3.rotation.y += 0.01;

    mesh3.position.set(0, 50, -100)
  

    renderer.render(scene, camera);

}