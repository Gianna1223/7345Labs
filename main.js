const {app, BrowserWindow} = require('electron')
const path = require('path')
const url = require('url')
 
let win
 
function createWindow () {
  // Create the browser window.
  win = new BrowserWindow({width: 800, height: 600})
 
  // and load the index.html of the app.
  win.loadURL(url.format({
    pathname: path.join(__dirname, 'index.html'),
    protocol: 'file:',
    slashes: true
  }))
 
  // Open the DevTools.
  //win.webContents.openDevTools()     
  // Emitted when the window is closed.
  win.on('closed', () => {
    win = null
  })
}
 
app.on('ready', createWindow)
 
// Quit when all windows are closed.
app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') {
    app.quit()
  }
})
 
app.on('activate', () => {
  if (win === null) {
    createWindow()
  }
})

 
const createWindow_tips = () => {
    // create window
    const mainWindow = new BrowserWindow({
        width: 800,
        height: 600,
        webPreferences: {
            // start node
            nodeIntegration: true,
            // De context isolation
            contextIsolation: false,
            // start remote
            enableRemoteModule:true,
        }
    });
    // Load local file
    mainWindow.loadFile(path.join(__dirname, "index.html"));
    // Load remote address
    // mainWindow.loadURL('https://github.com');
 
    // Turn on debugging mode
    mainWindow.webContents.openDevTools();
 
}
 
// Listen for application startup events
app.on("ready", createWindow_tips); 
// Windows closing function compatible with MacOS system
app.on("window-all-closed", () => {
    // Non MacOS direct exit
    if (process.platform != "darwin") {
        app.quit();
    }
});
 
// Restart the window when click the menu at the bottom of MacOS
app.on("activate", () => {
    if (BrowserWindow.getAllWindows.length == 0) {
      createWindow_tips();
    }
})