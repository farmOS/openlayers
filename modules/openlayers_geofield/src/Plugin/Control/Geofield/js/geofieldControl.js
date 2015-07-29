goog.provide('ol.control.GeoField');

goog.require('ol.control.Control');

ol.control.GeoField = function(opt_options) {
  var options = goog.isDef(opt_options) ? opt_options : {};
  var className = goog.isDef(options.className) ? options.className : 'ol-geofield';

  // This is for the global even at the top down the file.
  // Not needed now, but maybe later.
  var this_ = this;
  var handleClickEvent = function(e) {
    this_.handleClickEvent(e);
  };

  draw = options.draw || {};
  actions = options.actions || {};
  options = options.options || {};

  if (draw.Point) {
    var pointLabel = goog.isDef(options.pointLabel) ?
      options.pointLabel : '\u25CB';
    var pointTipLabel = goog.isDef(options.pointInTipLabel) ?
      options.pointTipLabel : 'Draw a point';
    var pointElement = goog.dom.createDom(goog.dom.TagName.BUTTON, {
      'class': className + '-point',
      'type' : 'button',
      'title': pointTipLabel
    }, pointLabel);
    goog.events.listen(pointElement,
      goog.events.EventType.CLICK, goog.partial(
        ol.control.GeoField.prototype.handleDrawClick_, 'Point'), false, this);
    ol.control.Control.bindMouseOutFocusOutBlur(pointElement);
  }

  if (draw.MultiPoint) {
    var multipointLabel = goog.isDef(options.multipointLabel) ?
      options.multipointLabel : '\u25CB';
    var multipointTipLabel = goog.isDef(options.multipointInTipLabel) ?
      options.multipointTipLabel : 'Draw a multipoint';
    var multipointElement = goog.dom.createDom(goog.dom.TagName.BUTTON, {
      'class': className + '-multipoint',
      'type': 'button',
      'title': multipointTipLabel
    }, multipointLabel);
    goog.events.listen(multipointElement,
      goog.events.EventType.CLICK, goog.partial(
        ol.control.GeoField.prototype.handleDrawClick_, 'MultiPoint'), false, this);
    ol.control.Control.bindMouseOutFocusOutBlur(multipointElement);
  }

  if (draw.LineString) {
    var linestringLabel = goog.isDef(options.linestringLabel) ?
      options.pointLabel : '\u2500';
    var linestringTipLabel = goog.isDef(options.linestringTipLabel) ?
      options.pointTipLabel : 'Draw a linestring, hold [shift] for free hand.';
    var linestringElement = goog.dom.createDom(goog.dom.TagName.BUTTON, {
      'class': className + '-linestring',
      'type' : 'button',
      'title': linestringTipLabel
    }, linestringLabel);
    goog.events.listen(linestringElement,
      goog.events.EventType.CLICK, goog.partial(
        ol.control.GeoField.prototype.handleDrawClick_, 'LineString'), false, this);
    ol.control.Control.bindMouseOutFocusOutBlur(linestringElement);
  }

  if (draw.MultiLineString) {
    var multilinestringLabel = goog.isDef(options.multilinestringLabel) ?
      options.pointLabel : '\u2500';
    var multilinestringTipLabel = goog.isDef(options.multilinestringTipLabel) ?
      options.pointTipLabel : 'Draw a multilinestring, hold [shift] for free hand.';
    var multilinestringElement = goog.dom.createDom(goog.dom.TagName.BUTTON, {
      'class': className + '-multilinestring',
      'type' : 'button',
      'title': multilinestringTipLabel
    }, multilinestringLabel);
    goog.events.listen(multilinestringElement,
      goog.events.EventType.CLICK, goog.partial(
        ol.control.GeoField.prototype.handleDrawClick_, 'MultiLineString'), false, this);
    ol.control.Control.bindMouseOutFocusOutBlur(multilinestringElement);
  }

  if (draw.Triangle) {
    var triangleLabel = goog.isDef(options.triangleLabel) ?
      options.triangleLabel : '\u25B2';
    var triangleTipLabel = goog.isDef(options.triangleTipLabel) ?
      options.triangleTipLabel : 'Draw a triangle';
    var triangleElement = goog.dom.createDom(goog.dom.TagName.BUTTON, {
      'class': className + '-triangle',
      'type' : 'button',
      'title': triangleTipLabel
    }, triangleLabel);
    goog.events.listen(triangleElement,
      goog.events.EventType.CLICK, goog.partial(
        ol.control.GeoField.prototype.handleDrawClick_, 'Triangle'), false, this);
    ol.control.Control.bindMouseOutFocusOutBlur(triangleElement);
  }

  if (draw.Square) {
    var squareLabel = goog.isDef(options.squareLabel) ?
      options.squareLabel : '\u25A0';
    var squareTipLabel = goog.isDef(options.squareTipLabel) ?
      options.squareTipLabel : 'Draw a square';
    var squareElement = goog.dom.createDom(goog.dom.TagName.BUTTON, {
      'class': className + '-square',
      'type' : 'button',
      'title': squareTipLabel
    }, squareLabel);
    goog.events.listen(squareElement,
      goog.events.EventType.CLICK, goog.partial(
        ol.control.GeoField.prototype.handleDrawClick_, 'Square'), false, this);
    ol.control.Control.bindMouseOutFocusOutBlur(squareElement);
  }

  if (draw.Box) {
    var boxLabel = goog.isDef(options.boxLabel) ?
      options.boxLabel : '\u25AE';
    var boxTipLabel = goog.isDef(options.boxTipLabel) ?
      options.boxTipLabel : 'Draw a box';
    var boxElement = goog.dom.createDom(goog.dom.TagName.BUTTON, {
      'class': className + '-box',
      'type' : 'button',
      'title': boxTipLabel
    }, boxLabel);
    goog.events.listen(boxElement,
      goog.events.EventType.CLICK, goog.partial(
        ol.control.GeoField.prototype.handleDrawClick_, 'Box'), false, this);
    ol.control.Control.bindMouseOutFocusOutBlur(boxElement);
  }

  if (draw.Circle) {
    var circleLabel = goog.isDef(options.circleLabel) ?
      options.circleLabel : '\u25CF';
    var circleTipLabel = goog.isDef(options.circleTipLabel) ?
      options.circleTipLabel : 'Draw a circle';
    var circleElement = goog.dom.createDom(goog.dom.TagName.BUTTON, {
      'class': className + '-circle',
      'type' : 'button',
      'title': circleTipLabel
    }, circleLabel);
    goog.events.listen(circleElement,
      goog.events.EventType.CLICK, goog.partial(
        ol.control.GeoField.prototype.handleDrawClick_, 'Circle'), false, this);
    ol.control.Control.bindMouseOutFocusOutBlur(circleElement);
  }

  if (draw.Polygon) {
    var polygonLabel = goog.isDef(options.polygonLabel) ?
      options.polygonLabel : '\u2B1F';
    var polygonTipLabel = goog.isDef(options.polygonTipLabel) ?
      options.polygonTipLabel : 'Draw a polygon';
    var polygonElement = goog.dom.createDom(goog.dom.TagName.BUTTON, {
      'class': className + '-polygon',
      'type' : 'button',
      'title': polygonTipLabel
    }, polygonLabel);
    goog.events.listen(polygonElement,
      goog.events.EventType.CLICK, goog.partial(
        ol.control.GeoField.prototype.handleDrawClick_, 'Polygon'), false, this);
    ol.control.Control.bindMouseOutFocusOutBlur(polygonElement);
  }

  if (draw.MultiPolygon) {
    var multipolygonLabel = goog.isDef(options.multipolygonLabel) ?
      options.multipolygonLabel : '\u2B1F';
    var multipolygonTipLabel = goog.isDef(options.multipolygonTipLabel) ?
      options.multipolygonTipLabel : 'Draw a multipolygon';
    var multipolygonElement = goog.dom.createDom(goog.dom.TagName.BUTTON, {
      'class': className + '-multipolygon',
      'type' : 'button',
      'title': multipolygonTipLabel
    }, multipolygonLabel);
    goog.events.listen(multipolygonElement,
      goog.events.EventType.CLICK, goog.partial(
        ol.control.GeoField.prototype.handleDrawClick_, 'MultiPolygon'), false, this);
    ol.control.Control.bindMouseOutFocusOutBlur(multipolygonElement);
  }

  if (actions.Select) {
    var selectLabel = goog.isDef(options.selectLabel) ?
      options.selectLabel : '\u270D';
    var selectTipLabel = goog.isDef(options.selectTipLabel) ?
      options.selectTipLabel : 'Edit features';
    var selectElement = goog.dom.createDom(goog.dom.TagName.BUTTON, {
      'class': className + '-select',
      'type' : 'button',
      'title': selectTipLabel
    }, selectLabel);
    goog.events.listen(selectElement,
      goog.events.EventType.CLICK, goog.partial(
        ol.control.GeoField.prototype.handleActionsClick_, 'Select'), false, this);
    ol.control.Control.bindMouseOutFocusOutBlur(selectElement);
  }

  if (actions.Move) {
    var moveLabel = goog.isDef(options.moveLabel) ?
      options.moveLabel : '\u27A4';
    var moveTipLabel = goog.isDef(options.moveTipLabel) ?
      options.moveTipLabel : 'Move features';
    var moveElement = goog.dom.createDom(goog.dom.TagName.BUTTON, {
      'class': className + '-move',
      'type': 'button',
      'title': moveTipLabel
    }, moveLabel);
    goog.events.listen(moveElement,
      goog.events.EventType.CLICK, goog.partial(
        ol.control.GeoField.prototype.handleActionsClick_, 'Move'), false, this);
    ol.control.Control.bindMouseOutFocusOutBlur(moveElement);
  }

  if (actions.Clear) {
    var clearLabel = goog.isDef(options.clearLabel) ?
      options.clearLabel : 'X';
    var clearTipLabel = goog.isDef(options.clearTipLabel) ?
      options.clearTipLabel : 'Clear features';
    var clearElement = goog.dom.createDom(goog.dom.TagName.BUTTON, {
      'class': className + '-clear',
      'type': 'button',
      'title': clearTipLabel
    }, clearLabel);
    goog.events.listen(clearElement,
      goog.events.EventType.CLICK, goog.partial(
        ol.control.GeoField.prototype.handleActionsClick_, 'Clear'), false, this);
    ol.control.Control.bindMouseOutFocusOutBlur(clearElement);
  }

  if (options.Snap) {
    var snapLabel = goog.isDef(options.snapLabel) ?
      options.snapLabel : '\u2609';
    var snapTipLabel = goog.isDef(options.snapTipLabel) ?
      options.snapTipLabel : 'Snap to features';
    var snapElement = goog.dom.createDom(goog.dom.TagName.BUTTON, {
      'class': className + '-snap',
      'type': 'button',
      'title': snapTipLabel
    }, snapLabel);
    goog.events.listen(snapElement,
      goog.events.EventType.CLICK, goog.partial(
        ol.control.GeoField.prototype.handleOptionsClick_, 'Snap'), false, this);
    ol.control.Control.bindMouseOutFocusOutBlur(snapElement);
  }

  var cssClasses = className + ' ' + ol.css.CLASS_CONTROL;

  var drawElements = goog.dom.createDom(goog.dom.TagName.DIV, 'draw', pointElement, multipointElement, linestringElement, multilinestringElement, triangleElement, squareElement, boxElement, polygonElement, multipolygonElement, circleElement);
  var actionsElements = goog.dom.createDom(goog.dom.TagName.DIV, 'actions', selectElement, moveElement, clearElement);
  var optionsElements = goog.dom.createDom(goog.dom.TagName.DIV, 'options', snapElement);

  var element = goog.dom.createDom(goog.dom.TagName.DIV, cssClasses, drawElements, actionsElements, optionsElements);

  element.addEventListener('click', handleClickEvent, false);

  goog.base(this, {
    element: element,
    target: options.target
  });
};
goog.inherits(ol.control.GeoField, ol.control.Control);

ol.control.GeoField.prototype.handleDrawClick_ = function(type, event) {
  // Disable actions buttons and options.
  goog.array.forEach(goog.dom.getChildren(goog.dom.getElementByClass('actions', this.element)), function(e, i, a) {
    goog.dom.classlist.remove(e, 'enable');
  });
  options = this.get('options') || {};
  options.actions = options.actions || {};
  options.actions[type] = true;
  this.set('options', options);

  // Disable other draw buttons except the one we've clicked.
  goog.array.forEach(goog.dom.getChildren(goog.dom.getElementByClass('draw', this.element)), function(e, i, a) {
    if (e != event.target) {
      goog.dom.classlist.remove(e, 'enable');
    }
  });
  goog.dom.classlist.toggle(event.target, 'enable');

  if (goog.dom.classlist.contains(event.target, 'enable')) {
    options = this.get('options') || {};
    options.draw = type;
    this.set('options', options);
  } else {
    options = this.get('options') || {};
    options.draw = false;
    this.set('options', options);
  }
};

ol.control.GeoField.prototype.handleOptionsClick_ = function(type, event) {
  goog.dom.classlist.toggle(event.target, 'enable');

  if (goog.dom.classlist.contains(event.target, 'enable')) {
    options = this.get('options') || {};
    options.options = options.options || {};
    options.options[type] = true;
    this.set('options', options);
  } else {
    options = this.get('options') || {};
    options.options[type] = false;
    this.set('options', options);
  }
};

ol.control.GeoField.prototype.handleActionsClick_ = function(type, event) {
  // Disable draw buttons and options.
  goog.array.forEach(goog.dom.getChildren(goog.dom.getElementByClass('draw', this.element)), function(e, i, a) {
    goog.dom.classlist.remove(e, 'enable');
  });
  options = this.get('options') || {};
  options.draw = false;
  this.set('options', options);

  // Disable other actions except the one we've clicked.
  goog.array.forEach(goog.dom.getChildren(goog.dom.getElementByClass('actions', this.element)), function(e, i, a) {
    if (e != event.target) {
      goog.dom.classlist.remove(e, 'enable');
    }
  });
  goog.dom.classlist.toggle(event.target, 'enable');

  if (goog.dom.classlist.contains(event.target, 'enable')) {
    options = this.get('options') || {};
    options.actions = options.actions || {};
    options.actions[type] = true;
    this.set('options', options);
  } else {
    options = this.get('options') || {};
    options.actions[type] = false;
    this.set('options', options);
  }
};

ol.control.GeoField.prototype.handleClickEvent = function(e) {
  // if we need a global event here.
};
